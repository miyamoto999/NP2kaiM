#!/usr/bin/env python3

# q98keymapアプリで保存したファイルから
# キーコード変換テーブルを生成する。(QtキーイベントのnativeVirtualKeyから変換するものを生成)

f = open('keymap_qt_macOS.txt', 'rt')

lines = f.readlines()
f.close()

transtable = ['KEYCODE98_NC'] * 256

for line in lines:
    datas = line.split('\t')
    if int(datas[2]) == 1:
        transtable[int(datas[7])] = datas[0]

print('static qint8 trans_table106[] = {')
for i in range(0, 16):
    print('\t', end='')
    for j in range(0,16):
        index = i * 16 + j
        print(transtable[index], end=', ')
    print()
print('};')

