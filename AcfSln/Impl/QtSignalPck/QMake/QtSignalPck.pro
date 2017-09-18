include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)

TARGET = QtSignalPck

LIBS += -L../../../Lib/$$COMPILER_DIR -liqtsig -limeas

include(../../../../Acf/Config/QMake/AcfQt.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)
