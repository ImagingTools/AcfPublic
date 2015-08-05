include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)
include(../../../../Acf/Config/QMake/AcfQt.pri)

TARGET = QwtPck

INCLUDEPATH += ../../../../AcfSln/Include
INCLUDEPATH += "$(QWTDIR_6_1_0)/Src"
INCLUDEPATH += "$(QWT3DDIR_0_3_1)/Include"

LIBS += -L../../../Lib/$$COMPILER_DIR -liqwt -liqwt3d
LIBS += -L$(QWTDIR_6_1_0)/Lib/$$COMPILER_DIR -lqwt
LIBS += -L$(QWT3DDIR_0_3_1)/Lib/$$COMPILER_DIR -lqwt3d

INCLUDEPATH += ../../../Include

QT += opengl
LIBS += -L../../../../Acf/Lib/$$COMPILER_DIR -liprm

