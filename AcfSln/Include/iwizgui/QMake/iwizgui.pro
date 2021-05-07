TARGET = iwizgui

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)

FORMS += $$files($$_PRO_FILE_PWD_/../*.ui, true)

