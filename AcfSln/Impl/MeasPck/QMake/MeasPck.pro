TARGET = MeasPck

include(..\..\..\..\Acf\Config/QMake/ComponentConfig.pri)
include(..\..\..\..\Acf\Config/QMake/QtBaseConfig.pri)

LIBS += -L../../../Lib/$$COMPILER_DIR -limeas -liproc -liinsp

include(..\..\..\..\Acf\Config/QMake/AcfQt.pri)
include(..\..\..\..\Acf\Config/QMake/AcfStd.pri)
