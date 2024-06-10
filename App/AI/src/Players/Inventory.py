#!/usr/bin/python3

class InventoryIteam:

    def __init__(self):
        self.items = {
            "food": 9,
            "linemate": 0,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
            "lvl": 1,
            "time since update": 0
        }

    def getItems(self):
        return self.items