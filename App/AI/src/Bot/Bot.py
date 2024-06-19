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
    BROADCAST_TEXT = "Broadcast text"
    CONNECT_NBR = "Connect_nbr"
    FORK = "Fork"
    EJECT = "Eject"
    TAKE_OBJECT = "Take "
    SET_OBJECT = "Set object"
    INCANTATION = "Incantation"
    NO_DETECTED_OBJECT = "No object"

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
        self.stones = Stones(0,0,0,0,0,0,1)

    def make_action(self, action : Action, target: Optional[Union[str, Object]] = None) -> ActionStatus:
        if action == Action.FORWARD:
            return ActionStatus.SUCCESS.value
        elif action == Action.RIGHT:
            return ActionStatus.SUCCESS.value
        elif action == Action.LEFT:
            return ActionStatus.SUCCESS.value
        else:
            return ActionStatus.INVALID_ACTION.value

    def write_incantation(self):
        with open('incantion.txt', 'w') as file:
            file.write("Incantation")

    def read_incantation(self):
        try:
            with open('incantion.txt', 'r') as file:
                content = file.read()
            return content
        except FileNotFoundError:
            return "The file 'incantation.txt' does not exist."

    def delete_incantion(self):
        try:
            os.remove('incantion.txt')
            return "The file has been deleted."
        except FileNotFoundError:
            return "The file 'incantation.txt' does not exist."
        except Exception as e:
            return "An error occurred"

    def parse_command(self, command: str) -> Action:
        words = command.split()
        if "Incantation" in self.read_incantation():
            self.delete_incantion()
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
                self.write_incantation()
            return Action.TAKE_OBJECT.value + words[1]
