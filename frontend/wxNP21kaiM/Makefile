OBJS=wxNP21kaiMBaseFrame.o wxNP21kaiMFrame.o wxNP21kaiMApp.o np2kaiapi.o
TARGET=wxNP21kaiM
CXX=$(shell wx-config --cxx)
CXXFLAGS+=$(shell wx-config --cxxflags)
CPPFLAGS=$(CXXFLAGS)
LDCONFIG=$(shell wx-config --libs)
POT=$(TARGET).pot

all:$(TARGET) $(POT) po/ja.mo po/ja.po

$(TARGET):$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDCONFIG)

$(POT):*.cpp *.h
	xgettext -k_ -kN_ -d $(TARGET) -o $(POT) *.cpp *.h

po/ja.po:$(POT)
	msgmerge po/ja.po $(POT) -o po/ja.po

po/ja.mo:po/ja.po
	msgfmt -o po/ja.mo po/ja.po
	mkdir -p locale/ja/LC_MESSAGES
	cp -p po/ja.mo locale/ja/LC_MESSAGES/$(TARGET).mo

init-po:
	xgettext -k_ -kN_ -d $(TARGET) -o $(POT) *.cpp *.h
	mkdir po
	msginit --locale ja_JP.UTF-8 --input $(POT) --output po/ja.po

clean:
	rm -rf $(OBJS) $(TARGET) $(TARGET).exe locale po/*.mo $(POT)

