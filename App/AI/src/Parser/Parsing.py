#!/usr/bin/python3

class Parser:
    def __init__(self, port, name, machine):
        self.port = port
        self.name = name
        self.machine = machine

    def get_port(self):
        return self.port
    
    def set_port(self, port):
        self.port = port

    def get_name(self):
        return self.name
    
    def set_name(self, name):
        self.name = name

    def get_machine(self):
        return self.machine
    
    def set_machine(self, machine):
        self.machine = machine

    def display_flags(self):
        print(f'Port: {self.port}, Name: {self.name}, Machine: {self.machine}')
