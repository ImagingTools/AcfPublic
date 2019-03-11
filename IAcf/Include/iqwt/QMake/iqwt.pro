TARGET = iqwt

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)
include($(IACFDIR)/Config/QMake/Qwt.pri)

INCLUDEPATH += ../../../../AcfSln/Include

FORMS += $$_PRO_FILE_PWD_/../*.ui
