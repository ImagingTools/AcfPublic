include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

TARGET = WinPck

INCLUDEPATH += ../../../../AcfSln/Include

LIBS += -L../../../Lib/$$COMPILER_DIR -liwin

