TARGET = iqwt3d

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)

INCLUDEPATH += ../..
INCLUDEPATH += "$(QWT3DDIR_0_3_1)/Include"

FORMS += ../*.ui
