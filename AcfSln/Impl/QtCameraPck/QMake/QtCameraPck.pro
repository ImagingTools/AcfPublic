include(..\..\..\..\Acf\Config/QMake/ComponentConfig.pri)
include(..\..\..\..\Acf\Config/QMake/QtBaseConfig.pri)

TARGET = QtCameraPck

LIBS += -L../../../Lib/$$COMPILER_DIR -liqtcam

include(..\..\..\..\Acf\Config/QMake/AcfQt.pri)
include(..\..\..\..\Acf\Config/QMake/AcfStd.pri)
