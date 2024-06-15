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

    def is_connected(self) -> bool:
        return self.sockfd is not None

    def readCsv(self, filename):
        with open(filename, mode='r') as f:
            csv_reader = csv.DictReader(f)

            for row in csv_reader:
                self.client[int(row['CLIENT-NUM'])] = {
                    'TEAM-NAME': row['TEAM-NAME'],
                    'STATUS': row['STATUS']
                }

    def connect(self):
        self.name = self.name.replace('\n', '')
        print(f"Connecting.. server on the port {self.port} with the team {self.name} in the host {self.machine}")
        self.sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sockfd.connect((self.machine, self.port))
        reponse = self.sockfd.recv(1024).decode('utf-8')
        print(f"<---{reponse}")
        self.name += "\n"
        print(f"---> TEAM-NAME {self.name}")
        self.sockfd.send(self.name.encode('utf-8'))
        reponse = self.sockfd.recv(1024).decode('utf-8')
        reponse = reponse.replace('\n',' ')
        client_num, map_size = reponse.split(' ', 1)
        print(f"<--- CLIENT-NUM {client_num}")
        size = map_size.split()
        self.xMap = size[0]
        self.yMap = size[1]
        print(f"<--- X Y {size}")

        client = [ [client_num, self.name.strip(), 'Connected'] ]

        with open('client_num.csv', 'a', newline='') as file:
            csv_writter = csv.writer(file)
            if not os.path.isfile('client_num.csv') or os.path.getsize('client_num.csv') == 0:
                csv_writter.writerow(['CLIENT-NUM', 'TEAM-NAME', 'STATUS'])
            for row in client:
                csv_writter.writerow(row)
        self.connect_nbr = self.client_connect('client_num.csv')
        self.readCsv('client_num.csv')

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

    def get_message_from_server(self) -> Optional[str]:
        return self.message

    def set_message_from_server(self, message) -> None:
        self.message = message

    def getLevel(self) -> int:
        return self.level

    def setLevel(self, level) -> None:
        self.level = level

    def getTeams(self) -> str:
        return self.team

    def setTeams(self, teams) -> None:
        self.team = teams

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
            return False
        if request == "help\n":
            print("\n".join(commands.keys()))
            return True
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
        return True

    def client_connect(self, filename):
        with open(filename, 'r') as f:
            lines = f.readlines()
        return len(lines) - 1

    def running_bot(self, debug : bool) -> None:
        counter = 0
        command = None

        def command_callback(cmd):
            nonlocal command
            command = cmd

        while self.request == 1:
            try:
                if counter % 2 == 0 or self.get_file_size('bot.txt') > 0:
                    if self.get_file_size('bot.txt') > 0:
                        time.sleep(10)
                        line = "Look\n"
                        self.delete_file('bot.txt')
                        counter = counter + 1
                    else:
                        line = "Look\n"
                else:
                    line = command + "\n"
                if not self.handle_request(line):
                    break
                if self.command is not None:
                    result_dict = self.command.createList(debug)
                    self.analyse.analyse_cases(result_dict,debug, command_callback)
            except EOFError:
                self.request = 0
            counter += 1

    def get_clientConnected(self):
        return self.connect_nbr

    def running_debug(self, debug : bool) -> None:
        while self.request == 1:
            try:
                line = input("Enter command : ") + "\n"
                if not self.handle_request(line):
                    break
                if self.command is not None:
                    result_dict = self.command.createList(debug)
            except EOFError:
                self.request = 0

    def run(self, debug: bool) -> None:
        if debug == True:
            self.running_debug(debug)
        else:
            self.running_bot(debug)