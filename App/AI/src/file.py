#!/usr/bin/python3

import os
import shutil

def create_folder(path):
    fullPath = os.path.join(os.getcwd(), path)
    if not os.path.exists(path):
        try:
            os.makedirs(fullPath)
            print(f"The folder {fullPath} has been created!")
        except Exception as e:
            print(f"Error: {e}")
    else:
        print(f"The folder {fullPath} already exists!")

def destroy_folder(path):
    folder_save = ['App', 'src']

    folder = [n for n in os.listdir(path) if os.path.isdir(os.path.join(path, n))]
    for f in folder:
        if f not in folder_save:
            fullpath = os.path.join(path, f)
            try:
                shutil.rmtree(fullpath)
                print(f"The folder {fullpath} has been destroyed!")
            except Exception as e:
                print(f"Error: {e}")