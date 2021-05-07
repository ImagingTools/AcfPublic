TARGET = ihotfgui

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)

RESOURCES += $$files($$_PRO_FILE_PWD_/../*.qrc, true)
FORMS += $$files($$_PRO_FILE_PWD_/../*.ui, true)

