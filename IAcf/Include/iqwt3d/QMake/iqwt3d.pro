TARGET = iqwt3d

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)
include($(IACFDIR)/Config/QMake/Qwt3d.pri)

INCLUDEPATH += ../..

FORMS += $$_PRO_FILE_PWD_/../*.ui
