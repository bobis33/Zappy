#!/usr/bin/python3

class LevelRequirements:
    def __init__(self):
        self.stones = {
            1: {"linemate": 1, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0},
            2: {"linemate": 1, "deraumere": 1, "sibur": 1, "mendiane": 0, "phiras": 0, "thystame": 0},
            3: {"linemate": 2, "deraumere": 0, "sibur": 1, "mendiane": 0, "phiras": 2, "thystame": 0},
            4: {"linemate": 1, "deraumere": 1, "sibur": 2, "mendiane": 0, "phiras": 1, "thystame": 0},
            5: {"linemate": 1, "deraumere": 2, "sibur": 1, "mendiane": 3, "phiras": 0, "thystame": 0},
            6: {"linemate": 1, "deraumere": 2, "sibur": 3, "mendiane": 0, "phiras": 1, "thystame": 0},
            7: {"linemate": 2, "deraumere": 2, "sibur": 2, "mendiane": 2, "phiras": 2, "thystame": 1}
        }

    def getStone(self):
        return self.stones

class Stones:
    def __init__(self, linemate, deraumere, sibur, mendiane, phiras, thystame, level):
        self._linemate = linemate
        self._deraumere = deraumere
        self._sibur = sibur
        self._mendiane = mendiane
        self._phiras = phiras
        self._thystame = thystame
        self._level = level

    @property
    def linemate(self):
        return self._linemate

    @linemate.setter
    def linemate(self, value):
        self._linemate = value

    @property
    def deraumere(self):
        return self._deraumere

    @deraumere.setter
    def deraumere(self, value):
        self._deraumere = value

    @property
    def sibur(self):
        return self._sibur

    @sibur.setter
    def sibur(self, value):
        self._sibur = value

    @property
    def mendiane(self):
        return self._mendiane

    @mendiane.setter
    def mendiane(self, value):
        self._mendiane = value

    @property
    def phiras(self):
        return self._phiras

    @phiras.setter
    def phiras(self, value):
        self._phiras = value

    @property
    def thystame(self):
        return self._thystame

    @thystame.setter
    def thystame(self, value):
        self._thystame = value

    @property
    def level(self):
        return self._level
    
    @level.setter
    def level(self, value):
        self._level = value

    def incantation(self):
        requirements = {
            1: {"linemate": 1, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0},
            2: {"linemate": 1, "deraumere": 1, "sibur": 1, "mendiane": 0, "phiras": 0, "thystame": 0},
            3: {"linemate": 2, "deraumere": 0, "sibur": 1, "mendiane": 0, "phiras": 2, "thystame": 0},
            4: {"linemate": 1, "deraumere": 1, "sibur": 2, "mendiane": 0, "phiras": 1, "thystame": 0},
            5: {"linemate": 1, "deraumere": 2, "sibur": 1, "mendiane": 3, "phiras": 0, "thystame": 0},
            6: {"linemate": 1, "deraumere": 2, "sibur": 3, "mendiane": 0, "phiras": 1, "thystame": 0},
            7: {"linemate": 2, "deraumere": 2, "sibur": 2, "mendiane": 2, "phiras": 2, "thystame": 1}
        }

        if self._level in requirements:
            require = requirements[self._level]
            if (self._linemate >= require["linemate"] and
                self._deraumere >= require["deraumere"] and
                self._sibur >= require["sibur"] and
                self._mendiane >= require["mendiane"] and
                self._phiras >= require["phiras"] and
                self._thystame >= require["thystame"]):
                self._level += 1
                self._linemate -= require["linemate"]
                self._deraumere -= require["deraumere"]
                self._sibur -= require["sibur"]
                self._mendiane -= require["mendiane"]
                self._phiras -= require["phiras"]
                self._thystame -= require["thystame"]
                print(f"Incantation successful! New level: {self._level}")
        else:
            print("Incantation failed.")

    def take_stone(self, stone_name):
        if stone_name == 'linemate':
            if self._level in [1, 2, 4, 5, 6]:
                self._linemate = 1
            elif self._level == 3 or self._level == 7:
                self._linemate += 1
        elif stone_name == 'deraumere':
            if self._level in [2, 4]:
                self._deraumere = 1
            elif self._level == 5 or self._level == 6 or self._level == 7:
                self._deraumere += 1
        elif stone_name == 'sibur':
            if self._level in [2, 3, 5]:
                self._sibur = 1
            elif self._level == 4 or self._level == 6 or self._level == 7:
                self._sibur += 1
        elif stone_name == 'mendiane' and self._level == 5:
            self._mendiane += 1
        elif stone_name == 'mendiane' and self._level == 7:
            self._mendiane += 1
        elif stone_name == 'phiras':
            if self._level == 3 or self._level == 7:
                self._phiras += 1
            elif self._level == 4 or self._level == 6:
                self._phiras = 1
        elif stone_name == 'thystame' and self._level == 7:
            self._thystame = 1
