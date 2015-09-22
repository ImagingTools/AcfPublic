TARGET = iqwt

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)

INCLUDEPATH += ../../../../AcfSln/Include
INCLUDEPATH += $(QWTDIR_6_1_0)/Src

FORMS += $$_PRO_FILE_PWD_/../*.ui
