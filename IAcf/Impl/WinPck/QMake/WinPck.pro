TARGET = WinPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

INCLUDEPATH += ../../../../AcfSln/Include

LIBS += -L../../../Lib/$$COMPILER_DIR -liwin

