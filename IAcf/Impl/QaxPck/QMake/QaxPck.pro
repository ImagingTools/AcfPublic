TARGET = QaxPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)
include(../../../../Acf/Config/QMake/AcfQt.pri)

QT += multimedia axcontainer

INCLUDEPATH += ../../../../AcfSln/Include

#LIBS += -L../../../../AcfSln/Lib/$$COMPILER_DIR -limm
LIBS += -L../../../Lib/$$COMPILER_DIR -liqaxmm

CONFIG(debug, debug|release){
	LIBS += -lQt5AxContainerd -lQt5AxBased
}
CONFIG(release, debug|release){
	LIBS += -lQt5AxContainer -lQt5AxBase
}

