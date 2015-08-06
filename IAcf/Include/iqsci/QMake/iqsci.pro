include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)

TARGET = iqsci

QT += xml

INCLUDEPATH += $(QSCINTILLA)/Include

FORMS += ../*.ui
UI_DIR = ../../GeneratedFiles/iqsci
