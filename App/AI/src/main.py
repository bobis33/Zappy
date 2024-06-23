#!/usr/bin/python3

import sys
import os
from src.Core import Core

def debugNeeded() -> bool:
    debug = input("Do you want to use debug mode [Y/N]: ")
    if debug.find("Y") != -1 or debug.find("y") != -1:
        return True
    return False
def remove_file_tmp(path):
    for n in os.listdir(path):
        if 'tmp' in n:
            os.remove(os.path.join(path, n))


if __name__ == "__main__":
    core = Core(len(sys.argv), sys.argv)
    core.dataTeams()
    debug = debugNeeded()
    if core.client.is_connected():
        exit(84)
    core.client.connect()
    core.client.run(debug)
    core.client.disconnect()
    core.client.delete_file('client_num.csv')
    core.client.delete_file('bot.txt')
    core.removeTeams()
    remove_file_tmp(".")
