TARGET = QsciPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)
include(../../../../Acf/Config/QMake/AcfQt.pri)

QT += xml

INCLUDEPATH += ../../../Include
INCLUDEPATH += "$(QSCINTILLA)/Include"
INCLUDEPATH += $(QSCINTILLA)/Qt4Qt5

LIBS += -L../../../Lib/$$COMPILER_DIR -liqsci
LIBS += -L$(QSCINTILLA)/Lib/$$COMPILER_DIR -lQScintilla

