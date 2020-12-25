#!/usr/bin/env python3
import subprocess
import os
import shutil
import sys

def printUsages():
    print("{} <build folder>".format(sys.argv[0]))

if len(sys.argv) != 2:
    printUsages()
    exit(1)

APP_DIR = "NP2kaiM.app"
CONTENTS_DIR = os.path.join(sys.argv[1], APP_DIR, "Contents")
EXEC_DIR = os.path.join(CONTENTS_DIR, "MacOS")
RESOURCES_DIR = os.path.join(CONTENTS_DIR, "Resources")
CMD_PATH = os.path.join(sys.argv[1], "sdlnp21kai")

print(CMD_PATH)
if not os.path.isfile(CMD_PATH):
    printUsages()
    exit(1)

# ライブラリパスのリスト
libs = []

# 使用しているDLLをリストアップする
def dlllistup(f):
    hoge = subprocess.check_output(["otool", "-L", f])
    lines = hoge.decode().split("\n")

    for line in lines:
        global libs
        datas = line.strip().split(" ")
        if datas[0] == "":
            continue
        if datas[0].find(f) == -1:
            if datas[0].find("/System/Library") == -1 and datas[0].find("/usr/lib") == -1:
                libs.append(datas[0])
                dlllistup(datas[0])

# 指定ファイルの使用しているライブラリを変更
def changelib(file):
    global libs
    print("# " + file)
    for f in libs:
        print("## " + f)
        subprocess.call(["install_name_tool", \
            "-change", f, os.path.join("@executable_path", os.path.basename(f)), \
                os.path.join(EXEC_DIR, os.path.basename(file))])

# ライブラリのリストアップ
dlllistup(CMD_PATH)

# 同じファイルを省く
libs = list(set(libs))

# appのディレクトリを作成
os.makedirs(EXEC_DIR, exist_ok=True)
os.makedirs(RESOURCES_DIR, exist_ok=True)

# sdlnp21kaiをコピー
shutil.copyfile(CMD_PATH, os.path.join(EXEC_DIR, os.path.basename(CMD_PATH)))
os.chmod(os.path.join(EXEC_DIR, os.path.basename(CMD_PATH)), 0o755)

# DLLをコピー
for f in libs:
    shutil.copyfile(f, os.path.join(EXEC_DIR, os.path.basename(f)))

# 実行ファイルやDLLに書き込まれているDLLパスを変更する。
changelib(os.path.join(EXEC_DIR, os.path.basename(CMD_PATH)))
for f in libs:
    changelib(f)

# Info.plistなどの必要なファイルをコピーする。
shutil.copyfile("Info.plist", os.path.join(CONTENTS_DIR, "Info.plist"))
shutil.copyfile("app.icns", os.path.join(RESOURCES_DIR, "app.icns"))
shutil.copyfile("run.sh", os.path.join(EXEC_DIR, "run.sh"))
os.chmod(os.path.join(EXEC_DIR, "run.sh"), 0o755)
