TARGET = iphonon

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)

FORMS += $$_PRO_FILE_PWD_/../*.ui
UI_DIR = ../../GeneratedFiles/iphonon

QT += phonon

