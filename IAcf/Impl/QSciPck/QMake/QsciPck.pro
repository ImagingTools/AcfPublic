include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)
include(../../../../Acf/Config/QMake/AcfQt.pri)

TARGET = QsciPck

QT += xml

INCLUDEPATH += ../../../Include
INCLUDEPATH += "$(QSCINTILLA)/Include"

LIBS += -L../../../Lib/$$COMPILER_DIR -liqsci
LIBS += -L$(QSCINTILLA)/Lib/$$COMPILER_DIR -lQScintilla

