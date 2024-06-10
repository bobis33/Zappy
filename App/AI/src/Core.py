#!/usr/bin/python3

from src.Parser.Parsing import Parser
from src.Client.Client import TCPClient

class Core:
    def __init__(self, ac, av):
        if ac < 7:
            print('Not enough arguments provided')
            exit(84)
        self.parser = Parser(int(av[2]), av[4], av[6])
        self.client = TCPClient(self.parser.get_port(), self.parser.get_name(), self.parser.get_machine())

    @property
    def get_parser(self):
        return self.parser
    
    def set_parser(self, parser):
        self.parser = parser

    @property
    def get_client(self):
        return self.client
    
    def set_client(self, client):
        self.client = client

    def getStatusRequest(self):
        return self.request
    
    def setStatusRequest(self, status):
        self.request = status

    def getCommand(self):
        return self.command