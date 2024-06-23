#!/usr/bin/python3
import socket
import sys
from typing import Optional
from enum import Enum
from src.Command.Command import commands, Command
from src.Players.Analysis import Analysis
import os
import time
import csv
import select
import re
def create_file(name, content=None):
    try:
        with open(name, 'w') as f:
            if content:
                f.write(content)
        print(f"The file {name} has been created!")
    except Exception as e:
        print(f"The file {name} could not be created!")


class REQUEST(Enum):
    TRUE = 1
    FALSE = 0

class TCPClient:

    def __init__(self, port: int, name: str, machine: str) -> None:
        self.port = port
        self.name = name + "\n"
        self.machine = machine
        self.request = REQUEST.TRUE.value
        self.sockfd = None
        self.level = 1
        self.team = self.name
        self.command = None
        self.xMap = 0
        self.yMap = 0
        self.connect_nbr = -1
        self.analyse = Analysis()
        self.client =  {}
        self.customer = name

    def is_connected(self) -> bool:
        return self.sockfd is not None

    def readCsv(self, filename):
        with open(filename, mode='r') as f:
            csv_reader = csv.DictReader(f)

            for row in csv_reader:
                self.client[int(row['CLIENT-NUM'])] = {
                    'TEAM-NAME': row['TEAM-NAME'],
                    'STATUS': row['STATUS'],
                    'SOCKET' : socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                }

    def connect(self):
        self.name = self.name.replace('\n', '')
        self.sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            print(f"Connecting.. server on the port {self.port} with the team {self.name} in the host {self.machine}")
            self.sockfd.connect((self.machine, self.port))
        except socket.error:
            exit(84)
        reponse = self.sockfd.recv(1024).decode('utf-8')
        print("-------SERVER PROTOCOL-------")
        print(f"<---{reponse}", end='')
        self.name += "\n"
        print(f"---> TEAM-NAME {self.name}",end='')
        self.sockfd.send(self.name.encode('utf-8'))
        reponse = self.sockfd.recv(1024).decode('utf-8')
        reponse = reponse.replace('\n',' ')
        client_num, map_size = reponse.split(' ', 1)
        self.client_num = client_num
        print(f"<--- CLIENT-NUM {client_num}")
        size = map_size.split()
        self.xMap = size[0]
        self.yMap = size[1]
        print(f"<--- X Y {size}")
        print("-----------------------------\n")
        client = [ [client_num, self.name.strip(), 'Connected'] ]
        path = os.path.join(self.customer, "client-" + str(client_num) + ".txt")
        print(f"The path is {path}")
        content = "I'm glad I logged on I'm the client " + str(client_num) + "\n"
        create_file(path, content)
        with open('client_num.csv', 'a', newline='') as file:
            csv_writter = csv.writer(file)
            if not os.path.isfile('client_num.csv') or os.path.getsize('client_num.csv') == 0:
                csv_writter.writerow(['CLIENT-NUM', 'TEAM-NAME', 'STATUS'])
            for row in client:
                csv_writter.writerow(row)
        self.connect_nbr = self.client_connect('client_num.csv')

    def getMap(self):
        my_map = {}
        my_map["x"] = self.xMap
        my_map["y"] = self.yMap
        return my_map

    def get_client_info(self, id_client):
        return self.client.get(id_client,"Client not found")

    def send_and_receive(self, message):
        self.send(message)
        reply = self.receive()
        print()
        return reply

    def receive(self) -> str:
        if not self.is_connected():
            print("Socket is not connected")
            sys.exit(84)
        try:
            data = self.sockfd.recv(1024)
            if not data:
                print("Connection closed by the server")
                sys.exit(84)
            return data.decode('utf-8')
        except socket.error as e:
            print("Receive failed")
            sys.exit(84)

    def disconnect(self) -> None:
        if self.is_connected():
            self.sockfd.close()
            self.sockfd = None

    def send(self, message: str):
        self.sockfd.send(message.encode('utf-8'))

    def send_request(self, request: str) -> str:
        self.send(request)
        response = self.receive()
        return response

    def getLevel(self) -> int:
        return self.level

    def getTeams(self) -> str:
        return self.team

    def write_file(self):
        with open('bot.txt', 'w') as file:
            file.write("Look")

    def get_file_size(self, filename):
        if os.path.isfile(filename):
            return os.path.getsize(filename)
        else:
            return 0

    def delete_file(self, filename):
        try:
            os.remove(filename)
            return "The file has been deleted"
        except FileNotFoundError:
            return "The file does not exist"
        except Exception as e:
            return "An error occurred while deleting the file"

    def handle_request(self, request: str):
        if request == "exit\n":
            return False, None
        if request == "help\n":
            print("\n".join(commands.keys()))
            return True, None
        reply = self.send_and_receive(request)
        reply = reply.lstrip()
        if reply[0] == "[":
            self.command = Command(self.getLevel(), self.getTeams(), reply)
        else:
            self.command = None
        if "Current level:" in reply:
            level = reply.split("Current level:")[1]
            self.level = int(level.strip())
        if "Elevation underway" in reply:
            self.write_file()
        print(f"---> {reply}", end='')
        self.readCsv('client_num.csv')
        return True, reply

    def client_connect(self, filename):
        with open(filename, 'r') as f:
            lines = f.readlines()
        return len(lines) - 1


    def running_bot(self, debug: bool) -> None:
        counter = 0

        while self.request == 1:
            try:
                if counter % 2 == 0 or self.get_file_size('bot.txt') > 0:
                    if self.get_file_size('bot.txt') > 0:
                        time.sleep(10)
                        line = "Look\n"
                        self.delete_file('bot.txt')
                    else:
                        line = "Look\n"
                else:
                    file_path = os.path.join(os.getcwd(), 'tmp-' +  self.get_current_client_id())
                    with open(file_path, 'r') as f:
                        cmd = f.read()
                        if "Broadcast" in cmd:
                            id_client = re.findall(r'\d+', cmd)
                            id_client[0] = id_client[0].strip()
                            if id_client[0] == str(self.get_current_client_id().strip()):
                                line = cmd + "\n"
                            else:
                                line = "Forward" + "\n"
                        else:
                            line = cmd + "\n"

                selector = [self.sockfd]
                readable, _, exceptional = select.select(selector, [], selector, 5)

                for s in readable:
                    if s is self.sockfd:
                        recv_line = s.recv(1024).decode()
                        if not recv_line:
                            print("Server closed connection")
                            self.request = 0
                            break
                        parser = recv_line.split(",")
                        if len(parser) > 1:
                            print(f"Client {self.get_current_client_id()} has received from server the message {parser[1]}")


                result_request, reply = self.handle_request(line)
                if not result_request:
                    self.request = 0
                    break
                if reply is not None and reply.find("client") != -1:
                    parser = reply.split(",")
                    if len(parser) > 1:
                        print(f"Client {self.get_current_client_id()} has received from server the message {parser[1]}")

                if self.command is not None:
                    result_dict = self.command.createList(debug, self.getLevel(), self.get_current_client_id())
                counter += 1

            except EOFError:
                self.request = 0
            except Exception as e:
                print(f"An error occurred: {e}")
                self.request = 0
    def get_clientConnected(self):
        return self.connect_nbr
    
    def get_current_client_id(self) -> str:
        return self.client_num

    def running_debug(self, debug: bool) -> None:
        selector = [self.sockfd, sys.stdin]

        while self.request == 1:
            try:
                readable, _, exceptional = select.select(selector, [], [])
                for s in readable:
                    if s is self.sockfd:
                        line = s.recv(1024).decode()
                        if not line:
                            print("Server closed connection")
                            self.request = 0
                            break
                        parser = line.split(",")
                        if len(parser) > 1:
                            print(
                                f"Client {self.get_current_client_id()} received message from server: {parser[1]}"
                            )
                    elif s is sys.stdin:
                        line = sys.stdin.readline().strip() + "\n"
                        result_request, reply = self.handle_request(line)
                        if not result_request:
                            self.request = 0
                            break

                if self.command is not None:
                    result_dict = self.command.createList(debug, self.getLevel(), self.get_current_client_id())
            except EOFError:
                self.request = 0
            except KeyboardInterrupt:
                self.request = 0
            except Exception as e:
                print(f"An error occurred: {e}")
                self.request = 0

    def run(self, debug: bool) -> None:
        if debug == True:
            self.running_debug(debug)
        else:
            self.running_bot(debug)
