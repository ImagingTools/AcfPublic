TARGET = iqtauth

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)

INCLUDEPATH += ../..

FORMS += $$files($$_PRO_FILE_PWD_/../*.ui, true)

