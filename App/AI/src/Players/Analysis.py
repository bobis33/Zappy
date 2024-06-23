#!/usr/bin/python3

from src.Players.Inventory import InventoryIteam
from src.Players.Level import LevelRequirements
from src.Bot.Bot import Bot, Action, ActionStatus
import logging
import math
import random
import os

class Analysis:

    def __init__(self):
        self.inventory = InventoryIteam()
        self.levelRequirement = LevelRequirements()
        self.logger = logging.getLogger(__name__)
        self.mostImportItem = ("no item", 1000, 0)
        self.lastMoreimportItem = ("no item", 1000, 0)
        self.bot = Bot()

    def calculate_distance(self, nb_case):
        return math.floor(math.sqrt(nb_case))

    def calculate_importance(self, dist_case, item_count, multiplier):
        return (dist_case + 1) * 5 + ((item_count + 1) / 2) * multiplier

    def recalcul_food(self, nb_case):
        distance_case = self.calculate_distance(nb_case)
        distance_case = distance_case - 1
        nb_food_player = self.inventory.items["food"]

        importance_multiplier = (distance_case + 1) * 5 + ((nb_food_player + 1) / 2) * 3
        if nb_food_player < 3:
            importance_multiplier = importance_multiplier * 0.5
        self.lastMoreimportItem = ("food", importance_multiplier, nb_case)

    def analyse_item(self, nb_case, item):
        dist_case = self.calculate_distance(nb_case)
        item_count = self.inventory.items[item]
        multiplier = 3 if item == "food" else 1
        importance = self.calculate_importance(dist_case, item_count, multiplier)
        if item == "food" and item_count < 3:
            importance = importance * 0.5

        if importance < self.mostImportItem[1]:
            self.mostImportItem = (item, importance, nb_case)
    def choose_direction(self, item):
        if item[2] == 1 or item[2] == 4 or item[2] == 9:
            return "Left"
        elif item[2] == 3 or item[2] == 8 or item[2] == 15:
            return "Right"
        else:
            return "Forward"

    def choose_action(self, item, last_item):
        result = []
        if self.mostImportItem[1] > self.lastMoreimportItem[1]:
            result.append(str(self.choose_direction(self.lastMoreimportItem)))
        else:
            if self.mostImportItem[2] == 0:
                result.append("Take " + str(self.mostImportItem[0]))
            else:
                result.append("Forward")
        return result

    def upgrade_last_more_important_item(self):
        if self.lastMoreimportItem[2] == 1 or self.lastMoreimportItem[2] == 3 or self.lastMoreimportItem[2] == 4 or self.lastMoreimportItem[2] == 8 or self.lastMoreimportItem[2] == 9 or self.lastMoreimportItem[2] == 15:
            if self.lastMoreimportItem[0] == "food":
                self.recalcul_food(self.lastMoreimportItem[2])
        else:
            self.lastMoreimportItem = ("no item", 1000, 0)

    def analyse_cases(self, dictal, debug, callback, current_level : int, client_nb : str, team : str, reply):
        self.lastMoreimportItem = self.mostImportItem
        self.upgrade_last_more_important_item()
        self.mostImportItem = ("no item", 1000, 0)
        for i, case in dictal.items():
            for item in case:
                if item in self.inventory.items:
                    self.analyse_item(i, item)
        action = self.choose_action(self.mostImportItem, self.lastMoreimportItem)
        command = action[0]
        cmd = self.bot.parse_command(command, current_level, client_nb, team, reply)
        with open('tmp-' + client_nb, 'w') as file:
            file.write(cmd)
        if cmd == "Take no":
            cmd = random.choice(["Left", "Right"])
        print("--------- COMMAND ---------")
        print(cmd.center(28))
        print("---------------------------")