#!/usr/bin/python3

from src.Players.Inventory import InventoryIteam
from src.Players.Level import LevelRequirements
from src.Bot.Bot import Bot, Action, ActionStatus
import logging

class Analysis:

    def __init__(self):
        self.inventory = InventoryIteam()
        self.levelRequirement = LevelRequirements()
        self.logger = logging.getLogger(__name__)
        self.mostImportItem = ("no item", 1000, 0)
        self.lastMoreimportItem = ("no item", 1000, 0)
        self.bot = Bot()

    def calculate_distance(self, nb_case):
        case_to_distance = {
            0: 0,
            2: 1,
            1: 2, 3: 2, 6: 2,
            5: 3, 12: 3, 7: 3,
            4: 4, 8: 4, 13: 4, 11: 4,
            10: 5, 14: 5,
            9: 6, 15: 6
        }
        return case_to_distance.get(nb_case, -1)

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

        print(f"importance of {item} on case {nb_case} : {importance}\n")
        print(f"distance of case {nb_case} : {dist_case}")

        if importance < self.mostImportItem[1]:
            self.mostImportItem = (item, importance, nb_case)


        if importance < self.mostImportItem[1]:
            self.mostImportItem = (item, nb_case)

    def choose_direction(self, item):
        if item[2] == 1 or item[2] == 4 or item[2] == 9:
            return "Left"
        elif item[2] == 3 or item[2] == 8 or item[2] == 15:
            return "Right"
        else:
            return "error"

    def choose_action(self, item, last_item):
        result = []
        if self.mostImportItem[1] > self.lastMoreimportItem[1]:
            result.append(str(self.choose_direction(self.lastMoreimportItem)))
            self.lastMoreimportItem = ("no item", 1000, 0)
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

    def analyse_cases(self, dictal, debug, callback):
        self.lastMoreimportItem = self.mostImportItem
        self.upgrade_last_more_important_item()
        self.mostImportItem = ("no item", 1000, 0)
        for i, case in dictal.items():
            for item in case:
                if item in self.inventory.items:
                    self.analyse_item(i, item)
        print(f"Most important item : {self.mostImportItem[0]} at case {self.mostImportItem[1]}")
        action = self.choose_action(self.mostImportItem, self.lastMoreimportItem)
        command = action[0]

        command = self.bot.parse_command(command)
        print("Command: " + command)
        callback(command)
