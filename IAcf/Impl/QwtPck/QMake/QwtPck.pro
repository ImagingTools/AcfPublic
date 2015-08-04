include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)
include(../../../../Acf/Config/QMake/AcfQt.pri)

TARGET = QwtPck

INCLUDEPATH += C:\Temp\AcfSln/Include
INCLUDEPATH += "C:\Temp\AcfPublic\3rdParty\Qwt\6.1.0/Src"
INCLUDEPATH += "C:\Temp\AcfPublic\3rdParty\Qwt3D\0.3.1/Include"

LIBS += -L../../../Lib/$COMPILER_DIR -liqwt -liqwt3d
LIBS += -LC:\Temp\AcfPublic\3rdParty\Qwt\6.1.0/Lib/$COMPILER_DIR -lqwt
LIBS += -LC:\Temp\AcfPublic\3rdParty\Qwt3D\0.3.1/Lib/$COMPILER_DIR -lqwt3d

INCLUDEPATH += ../../../Include

QT += opengl
LIBS += -LC:\Temp\Acf/Lib/$COMPILER_DIR -liprm

