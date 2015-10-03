TARGET = icmpstr

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)

RESOURCES += $$_PRO_FILE_PWD_/../*.qrc
FORMS += $$_PRO_FILE_PWD_/../*.ui

LIBS += -licomp
LIBS += -liqtgui
