#!/usr/bin/python3

from src.Players.Analysis import Analysis

commands = {
    "Right": None,
    "Left": None,
    "Look": None,
    "Inventory": None,
    "Broadcast text": None,
    "Connect_nbr": None,
    "Fork": None,
    "Eject": None,
    "-": None,
    "Take object": None,
    "Set object": None,
    "Incantation": None,
    "exit": None
}

class Command:
    def __init__(self, level, team, infoServer):
        self.level = level
        self.team = team
        self.infoServer = infoServer
        self.analysis = Analysis()

    def getLevel(self):
        return self.level

    def getTeam(self):
        return self.team

    def setTeams(self, teams):
        self.team = teams

    def setLevel(self, level):
        self.level = level

    def getInfoServer(self):
        return self.infoServer

    def setInfoServer(self, infoServer):
        return self.infoServer

    def countListRequired(self):
        list = str(self.infoServer)
        counter = list.count(',')
        counter += 1
        return counter

    def parseElm(self, info : str) -> str:
        newinfo = info.replace('[', '')
        result = newinfo.replace(']', '')
        return result


    def createList(self, debug, current_level, reply):
        print(f'LEVEL: {self.getLevel()}')
        count = self.countListRequired()
        info = str(self.infoServer)
        info = self.parseElm(info)
        lst = info.split(',')
        newList = []
        for k in lst:
            remove_space = k.strip()
            split_k = remove_space.split()
            newList.append(split_k)
        lst = newList
        result_dict = {}
        for i in range(count):
            if i < len(lst):
                result_dict[i] = lst[i]
            else:
                result_dict[i] = []
        command = self.analysis.analyse_cases(result_dict, debug, lambda x:None, self.getLevel(), reply)
        return result_dict, command

    def __repr__(self) -> str:
        return str(self.infoServer)