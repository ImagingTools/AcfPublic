TARGET = CompositorPck

include(..\..\..\..\Acf\Config/QMake/ComponentConfig.pri)
include(..\..\..\..\Acf\Config/QMake/QtBaseConfig.pri)

LIBS += -L../../../Lib/$$COMPILER_DIR -licmpstr

QT += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

include(..\..\..\..\Acf\Config/QMake/AcfQt.pri)
include(..\..\..\..\Acf\Config/QMake/AcfStd.pri)
