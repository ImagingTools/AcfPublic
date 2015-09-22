include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

TARGET = MePck

INCLUDEPATH += ../../../../AcfSln/Include
INCLUDEPATH += $(MEIDSDIR)/include

LIBS += -L$(MEIDSDIR)/lib -lmeIDSmain


