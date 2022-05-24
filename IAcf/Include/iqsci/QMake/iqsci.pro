TARGET = iqsci

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)

QT += xml

INCLUDEPATH += $(QSCINTILLA)/Include
INCLUDEPATH += $(QSCINTILLA)/Qt4Qt5

FORMS += $$files($$_PRO_FILE_PWD_/../*.ui, false)
UI_DIR = ../../GeneratedFiles/iqsci

