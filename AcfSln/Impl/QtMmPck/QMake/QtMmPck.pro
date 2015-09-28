include(..\..\..\..\Acf\Config/QMake/ComponentConfig.pri)
include(..\..\..\..\Acf\Config/QMake/QtBaseConfig.pri)

TARGET = QtMmPck

QT += svg

LIBS += -L../../../Lib/$$COMPILER_DIR -liqtmm

include(..\..\..\..\Acf\Config/QMake/AcfQt.pri)
include(..\..\..\..\Acf\Config/QMake/AcfStd.pri)
