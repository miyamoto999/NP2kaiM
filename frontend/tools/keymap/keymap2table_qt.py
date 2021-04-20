#!/usr/bin/env python3

# q98keymapアプリで保存したファイルから
# キーコード変換テーブルを生成する。(QtキーイベントのnativeVirtualKeyまたはnativeScanCodeから変換するものを生成)
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('filename')
parser.add_argument('--scancode', '-s', action='store_true')
args = parser.parse_args()

if args.scancode == True:
    data_index = 6
else:
    data_index = 7
FLAG_INDEX = 2
KEYNAME_INDEX = 0

f = open(args.filename, 'rt')

lines = f.readlines()
f.close()

transtable_dic = {}

for line in lines:
    datas = line.split('\t')
    if int(datas[FLAG_INDEX]) == 1:
        code = int(datas[data_index])
        if code > 0xffff:
            continue
        key = (code >> 8) & 0xff
        idx = code & 0xff
        if (key in transtable_dic.keys()) == False:
            transtable_dic[key] = ['KEYCODE98_NC'] * 256
        transtable_dic[key][idx] = datas[KEYNAME_INDEX]

sorted_keys = sorted(transtable_dic.keys())

for key in sorted_keys:
    print('static const quint8 trans_table106_{:02x}[] = '.format(key), end='')
    print('{')
    for i in range(0, 32):
        print('\t', end='')
        for j in range(0,8):
            index = i * 8 + j
            print(transtable_dic[key][index], end=', ')
        print()
    print('};')
    print()

print('static const quint8 *trans_table106[] = {')
for i in range(0, 32):
    print('\t', end='')
    for j in range(0, 8):
        index = i * 8 + j
        if (index in transtable_dic.keys()) == True:
            print('trans_table106_{:02x}'.format(index), end=', ')
        else:
            print('NULL', end=', ')
    print()
print('};')
            
