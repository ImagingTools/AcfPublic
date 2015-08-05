include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

TARGET = CboxPck

QT -= gui core

LIBS += -L../../../Lib/$$COMPILER_DIR -licbox
LIBS += -L"$(CBIOSDIR)/lib/$$COMPILER_NAME" -lcbios -lwsock32

INCLUDEPATH += ../../../Include
INCLUDEPATH += "$(CBIOSDIR)/include" 


