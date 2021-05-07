TARGET = iqwt

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)
include(../../..//Config/QMake/Qwt.pri)

INCLUDEPATH += ../../../../AcfSln/Include

FORMS += $$files($$_PRO_FILE_PWD_/../*.ui, true)

