#!/usr/bin/python3

from enum import Enum
from typing import Union, Optional, List
from src.Players.Level import Stones
import os


class Action(Enum):
    FORWARD = "Forward"
    RIGHT = "Right"
    LEFT = "Left"
    LOOK = "Look"
    INVENTORY = "Inventory"
    BROADCAST_TEXT = "Broadcast "
    CONNECT_NBR = "Connect_nbr"
    FORK = "Fork"
    EJECT = "Eject"
    TAKE_OBJECT = "Take "
    SET_OBJECT = "Set object"
    INCANTATION = "Incantation"
    NO_DETECTED_OBJECT = "No object"

class Broadcast(Enum):
    WANT_INCANTATION = "I'm ready to level up"
    CONNECTED = "My authenticated connection is established"
    DEAD = "I dead"
    FOUND_FOOD = "I found a food "

class ActionStatus(Enum):
    SUCCESS = "Success"
    FAILURE = "Failure"
    INVALID_ACTION = "Invalid action"

class Object:
    def __init__(self, name: str, description: str):
        self.name = name
        self.describe = description

class Bot:

    def __init__(self, command: list[Object] = 0):
        self.command = command
        self.stones = None


    def make_action(self, action : Action, target: Optional[Union[str, Object]] = None) -> ActionStatus:
        if action == Action.FORWARD:
            return ActionStatus.SUCCESS.value
        elif action == Action.RIGHT:
            return ActionStatus.SUCCESS.value
        elif action == Action.LEFT:
            return ActionStatus.SUCCESS.value
        else:
            return ActionStatus.INVALID_ACTION.value

    def write_incantation(self, client_nb):
        with open('incantion-' + client_nb + ".txt", 'w') as file:
            file.write("Incantation")

    def read_incantation(self, client_nb):
        try:
            with open('incantion-' + client_nb + ".txt", 'r') as file:
                content = file.read()
            return content
        except FileNotFoundError:
            return "The file 'incantation.txt' does not exist."

    def delete_incantion(self, client_nb):
        try:
            os.remove('incantion-' + client_nb + ".txt")
            return "The file has been deleted."
        except FileNotFoundError:
            return "The file 'incantation.txt' does not exist."
        except Exception as e:
            return "An error occurred"

    def read_file(self):
        exclude_folders = ["App", "src"]
        lst = []
        for root, dirs, files in os.walk('.'):
            if not any(folder in root.split(os.path.sep) for folder in exclude_folders):
                for file in files:
                    if file.find("client") != -1 and file.find(".txt") != -1:
                        file_path = os.path.join(root, file)
                        with open(file_path, 'r') as f:
                            content = f.read()
                        if content.strip():
                            lst.append(content)
                            with open(file_path, "w") as file:
                                file.write("")
                            return lst
        return []

    def parse_command(self, command: str, current_level, client_nb) -> Action:
        self.stones = Stones(0, 0, 0, 0, 0, 0, current_level)
        words = command.split()
        lst = self.read_file()
        if len(lst) > 0:
            return Action.BROADCAST_TEXT.value + '"' + lst[0].strip() + '"'
        if "Incantation" in self.read_incantation(client_nb):
            self.delete_incantion(client_nb)
            return Action.INCANTATION.value
        elif "Forward" in words:
            return Action.FORWARD.value
        elif "Right" in words:
            return Action.RIGHT.value
        elif "Left" in words:
            return Action.LEFT.value
        elif "Take no" in words:
            return Action.FORWARD.value
        elif "Take" in words:
            stones_name = words[1]
            if self.stones.take_stone(stones_name) == True:
                self.write_incantation(client_nb)
            return Action.TAKE_OBJECT.value + words[1]