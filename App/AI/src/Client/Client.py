#!/usr/bin/python3

import socket
import sys
from typing import Optional
from enum import Enum
from src.Command.Command import commands, Command

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
    
    def is_connected(self) -> bool:
        return self.sockfd is not None
    
    def connect(self):
        self.name = self.name.replace('\n', '')
        print(f"Connecting.. server on the port {self.port} with the team {self.name} in the host {self.machine}")
        self.sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sockfd.connect((self.machine, self.port))
        reponse = self.sockfd.recv(1024).decode('utf-8')
        print(reponse)
        self.name += "\n"
        self.sockfd.send(self.name.encode('utf-8'))
        reponse = self.sockfd.recv(1024).decode('utf-8')
        print(reponse)

    def send_and_receive(self, message):
        self.send(message)
        reply = self.receive()
        print("Infos server: ")
        print(reply)
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
        return True

    def run(self, debug: bool):
        request = "Look\n"
        look_next = True
        
        while self.request == 1:
            try:
                if not self.handle_request(request):
                    break
                if self.command is not None:
                    result_dict, analyse = self.command.createList(debug)
                    print(f"Dict: -> {result_dict}")
                    print(f"Analyse: -> {analyse}")
                    if look_next:
                        request = "Look\n"
                    else:
                        request = f"{analyse}\n"
                    look_next = not look_next 
            except EOFError:
                self.request = 0