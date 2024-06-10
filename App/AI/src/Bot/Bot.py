#!/usr/bin/python3

from enum import Enum
from typing import Union, Optional, List
from src.Players.Level import Stones

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

    def parse_command(self, command: str) -> Action:
        words = command.split()
        if "Forward" in words:
            return Action.FORWARD.value
        elif "Right" in words:
            return Action.RIGHT.value
        elif "Left" in words:
            return Action.LEFT.value
        elif "Take" in words:
            stones_name = words[1]
            self.stones.take_stone(stones_name)
            return Action.TAKE_OBJECT.value + words[1]
        else:
            return Action.INCANTATION.value
