#!/usr/bin/env python3
import subprocess
import os
import shutil
import sys

def printUsages():
    print("{} <dll filename> <copy folder>".format(sys.argv[0]))

if len(sys.argv) != 3:
    printUsages()
    exit(1)

DLLFILENAME = sys.argv[1]
COPYDIR = sys.argv[2]

print(os.environ["WINDIR"])
windir = subprocess.check_output(["cygpath", os.environ["WINDIR"]])
windir = windir.decode().replace("\n", "") + "/"
windir = windir.lower()
print(windir)

# ライブラリパスのリスト
libs = []

# 使用してるDLLをリストアップする。
def dlllistup(f):
    hoge = subprocess.check_output(["ldd", f])
    lines = hoge.decode().split("\n")

    for line in lines:
        global libs
        datas = line.strip().split(" ")
        if datas[0] == "":
            continue
        if datas[2].find(f) == -1:
            if datas[2].lower().find(windir) == -1:
                try:
                    libs.index(datas[2])
                except ValueError:
                    print(datas[2])
                    libs.append(datas[2])
                    dlllistup(datas[2]) 

dlllistup(DLLFILENAME)

libs = list(set(libs))

# ライブラリをコピー
shutil.copyfile(DLLFILENAME, os.path.join(COPYDIR, os.path.basename(DLLFILENAME)))

for f in libs:
    copy_from = subprocess.check_output(["cygpath", "-w", f])
    copy_from = copy_from.decode().replace("\n", "")
    print("copy file:" + copy_from)
    copy_to = os.path.join(COPYDIR, os.path.basename(f))
    copy_to = subprocess.check_output(["cygpath", "-w", copy_to])
    copy_to = copy_to.decode().replace("\n", "")
    print("copy to:" + copy_to)
    shutil.copyfile(copy_from, copy_to)
