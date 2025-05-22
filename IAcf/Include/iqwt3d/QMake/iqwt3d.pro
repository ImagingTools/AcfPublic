TARGET = iqwt3d

greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)
include(../../..//Config/QMake/Qwt3d.pri)

INCLUDEPATH += ../..

FORMS += $$files($$_PRO_FILE_PWD_/../*.ui, false)

