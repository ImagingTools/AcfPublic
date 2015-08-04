include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)

TARGET = QtInspectionPck

LIBS += -L../../../Lib/$$COMPILER_DIR -liqtinsp

include(../../../../Acf/Config/QMake/AcfQt.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)
