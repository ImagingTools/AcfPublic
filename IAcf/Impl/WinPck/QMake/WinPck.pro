include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

TARGET = WinPck

INCLUDEPATH += C:\Temp\AcfSln/Include

LIBS += -L../../../Lib/$$COMPILER_DIR -liwin

