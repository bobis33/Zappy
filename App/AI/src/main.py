#!/usr/bin/python3

import sys

from src.Core import Core

def debugNeeded() -> bool:
    debug = input("Do you want to use debug mode [Y/N]: ")
    if debug.find("Y") != -1 or debug.find("y") != -1:
        return True
    return False

if __name__ == "__main__":
    core = Core(len(sys.argv), sys.argv)
    debug = debugNeeded()
    if core.client.is_connected():
        exit(84)
    core.client.connect()
    core.client.run(debug)
    core.client.disconnect()
    core.client.delete_file('client_num.csv')
    core.client.delete_file('bot.txt')