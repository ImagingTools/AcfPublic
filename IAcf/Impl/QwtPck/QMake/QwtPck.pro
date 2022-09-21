TARGET = QwtPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)
include(../../../../Acf/Config/QMake/AcfQt.pri)
include(../../..//Config/QMake/Qwt.pri)
include(../../..//Config/QMake/Qwt3d.pri)

QT += opengl

INCLUDEPATH += ../../../../AcfSln/Include

LIBS += -L../../../Lib/$$COMPILER_DIR -liqwt -liqwt3d
LIBS += -L../../../../Acf/Lib/$$COMPILER_DIR -liprm

win32{
	LIBS += -lopengl32 -lglu32
}

