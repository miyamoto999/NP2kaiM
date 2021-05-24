OBJS=wx98keymapForms.o wx98keymap.o wx98KeymapApp.o keywidget.o keydata.o keydialog.o \
		inputkeydialog.o inputkeyframe.o
TARGET=wx98keymap
CXX=$(shell wx-config --cxx)
CXXFLAGS=-O2 -Wall
CXXFLAGS+=$(shell wx-config --cxxflags)
#CPPFLAGS=$(CXXFLAGS)
#LDCONFIG=$(shell wx-config --libs) -lld
LDCONFIG=$(shell wx-config --libs)
POT=$(TARGET).pot

all:$(TARGET)

$(TARGET):$(OBJS) po/ja.mo
	$(CXX) -o $(TARGET) $(OBJS) $(LDCONFIG)

$(POT):*.cpp *.h
	xgettext -k_ -kN_ -d $(TARGET) -o $(POT) *.cpp *.h

po/ja.po:$(POT)
	msgmerge po/ja.po $(POT) -o po/ja.po

po/ja.mo:po/ja.po
	msgfmt -o po/ja.mo po/ja.po
	mkdir -p locale/ja/LC_MESSAGES
	cp -p po/ja.mo locale/ja/LC_MESSAGES/$(TARGET).mo

update-po:$(POT) po/ja.po

init-po:
	xgettext -k_ -kN_ -d $(TARGET) -o $(POT) *.cpp *.h
	mkdir -p po
	msginit --locale ja_JP.UTF-8 --input $(POT) --output po/ja.po

clean:
	rm -rf $(OBJS) $(TARGET) $(TARGET).exe locale po/*.mo depends

depend:
	$(CXX) $(CXXFLAGS) -E -MM -w *.cpp > depends


-include depends
