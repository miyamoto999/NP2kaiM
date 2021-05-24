#!/usr/bin/env python3

# docフォルダにあるpc-98key.drawioをxmlでエクスポートしたpc-98key.xmlを
# QtまたはwxWidgets用のC言語ソースに変換する。
import xml.etree.ElementTree as ET
import copy
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--wx', action='store_true')
args = parser.parse_args()

# 矩形クラス
class Rect:
    def __init__(self, x = 0, y = 0, width = 0, height = 0):
        self.x = x
        self.y = y
        self.width = width
        self.height = height

# キーデータクラス
class KeyData:
    def __init__(self, keyname, keytop, keycode):
        self.keyname = keyname
        self.keytop = keytop
        self.keycode = keycode
        self.rect = Rect()
    # 次の__eq__()と__hash__()はset()でkeynameが同じデータを
    # 取り除いたリストを作成するのに必要
    def __eq__(self, other):
        if not isinstance(other, KeyData):
            return False
        return self.keyname == other.keyname
    def __hash__(self):
        return hash(self.keyname)
    # 矩形の座標をずらす
    def moveRect(self, offx, offy):
        data = copy.deepcopy(self)
        data.rect.x += offx
        data.rect.y += offy
        return data

keydatas = []

# xmlを読み込みキーデータのリストを作る
tree = ET.parse("pc-98key.xml")
root = tree.getroot()
for obj in root.iter('object'):
    keyname = obj.attrib['keycode']
    keytop = obj.attrib['label']
    keycode = int(obj.attrib['keycode-val'], 0)
    keydata = KeyData(keyname, keytop, keycode)
    for obj2 in obj.iter('mxGeometry'):
        x = int(obj2.attrib['x'])
        y = int(obj2.attrib['y'])
        width = int(obj2.attrib['width'])
        height = int(obj2.attrib['height'])
        keydata.rect = Rect(x, y, width, height)
    keydatas.append(keydata)


# キー矩形の最小座標を求めてキー矩形の座標をずらす。
minx = int(min(d.rect.x for d in keydatas))
miny = int(min(d.rect.y for d in keydatas))
movedKeydatas = [d.moveRect(-minx, -miny) for d in keydatas]

# キーデータをPC98キー名でソートし同じキー名を
# 持つデータを取り除いたリストを作る。
# sortedKeydatas = sorted(movedKeydatas, key=lambda d:d.keycode)
# uniKeydatas = set(sortedKeydatas)

uniKeydatas = set(movedKeydatas)
uniSortedKeydatas = sorted(uniKeydatas, key=lambda d:d.keycode) 

# uniKeydatasからキーコード名とPC98キーコードの列挙型のソースコードを出力する。
print('enum _keycode98 {')
for data in uniSortedKeydatas:
    print('\t' + data.keyname + ' = ' + hex(data.keycode) + ', ')
print('\tKEYCODE98_NC = 0xff,')
print('};')

print()

# キーデータの配列のソースコードを出力する。
sortedKeydatas = sorted(movedKeydatas, key=lambda d:d.keycode)
print("KEYDATA keydatas[] ={")
for data in sortedKeydatas:
    if args.wx :
        print('\t{ wxString("', end='')
        print(data.keyname, end='')
        print('")', end=', ')
        print('wxString("', end='')
        print(data.keytop.replace("\\", "\\\\"), end='')
        print('")', end=', ')
        print(data.keyname, end=', ')
        print('wxRect(', end='')
        print(data.rect.x, end=', ')
        print(data.rect.y, end=', ')
        print(data.rect.width, end=', ')
        print(data.rect.height, end='), ')
        print('0', end=', ')
        print('0', end=', ')
        print('0', end=', ')
        print('0', end=', ')
        print('0', end=' }')
        print(",")
    else:
        print('\t{ QString("', end='')
        print(data.keyname, end='')
        print('")', end=', ')
        print('QString("', end='')
        print(data.keytop.replace("\\", "\\\\"), end='')
        print('")', end=', ')
        print(data.keyname, end=', ')
        print('QRect(', end='')
        print(data.rect.x, end=', ')
        print(data.rect.y, end=', ')
        print(data.rect.width, end=', ')
        print(data.rect.height, end='), ')
        print('0', end=', ')
        print('Qt::NoModifier', end=', ')
        print('0', end=', ')
        print('0', end=', ')
        print('0', end=', ')
        print('0', end=' }')
        print(",")
if args.wx :
    print("\t{ wxString(), wxString(), 0, wxRect(-1,-1,-1,-1), 0, 0, 0, 0, 0 }")
else:
    print("\t{ QString(), QString(), 0, QRect(-1,-1,-1,-1), 0, Qt::NoModifier, 0, 0, 0, 0 }")
print("};")

