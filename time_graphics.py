import subprocess
from pathlib import *
import matplotlib.pyplot as plt
import os

def save(name='', fmt='png'):
    pwd = os.getcwd()
    iPath = './pictures/{}'.format(fmt)
    if not os.path.exists(iPath):
        os.mkdir(iPath)
    os.chdir(iPath)
    plt.savefig('{}.{}'.format(name, fmt), fmt='png')
    os.chdir(pwd)

if __name__ == "__main__":
    path = PurePath(r'C:\Users\Julia\source\repos\x64\Release\Trees.exe')
    list_Size = []
    list_Time = []

    for Size in range(1000, 10000000, 1000000):
        list_Size.append(int(Size))
        tree = 0 #AVL = 0, Splay = 2
        action = 0 #Insert = 0, Search = 1, Delete = 2
        element = 23

        command = f"{Size} {tree} {action} {element}"
        output = subprocess.check_output(f"{path} {command}",shell=True, universal_newlines=True)
        _, output = output.split("Time : ")
        print(Size)
        print(output)
        list_Time.append(float(output))


    fig = plt.figure()
    grid1 = plt.grid(True)
    graph1 = plt.plot(list_Size, list_Time, label="Insert in avl tree", color='red')

    list_Time.clear()
    list_Size.clear()
    for Size in range(1000, 10000000, 1000000):
        list_Size.append(int(Size))
        tree = 1 #AVL = 0, Splay = 1, Red-Black = 2, BinarySearch = 3
        action = 0 #Insert = 0, Search = 1, Delete = 2
        element = 23

        command = f"{Size} {tree} {action} {element}"
        output = subprocess.check_output(f"{path} {command}",shell=True, universal_newlines=True)
        _, output = output.split("Time : ")
        print(Size)
        print(output)
        list_Time.append(float(output))
    graph2 = plt.plot(list_Size, list_Time, label="Insert in splay tree", color='blue')
    list_Time.clear()
    list_Size.clear()

    for Size in range(1000, 10000000, 1000000):
        list_Size.append(int(Size))
        tree = 2 #AVL = 0, Splay = 1, Red-Black = 2, BinarySearch = 3
        action = 0 #Insert = 0, Search = 1, Delete = 2
        element = 23

        command = f"{Size} {tree} {action} {element}"
        output = subprocess.check_output(f"{path} {command}",shell=True, universal_newlines=True)
        _, output = output.split("Time : ")
        print(Size)
        print(output)
        list_Time.append(float(output))

    graph3 = plt.plot(list_Size, list_Time, label="Insert in red-black tree", color='green')
    list_Time.clear()
    list_Size.clear()
    #save("Insert", 'png')
    plt.show()