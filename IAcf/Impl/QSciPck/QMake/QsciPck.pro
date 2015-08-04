include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)
include(../../../../Acf/Config/QMake/AcfQt.pri)

TARGET = QsciPck

QT += xml

INCLUDEPATH += ../../../Include
INCLUDEPATH += "C:\Temp\AcfPublic\3rdParty\QScintilla/Include"

LIBS += -L../../../Lib/$COMPILER_DIR -liqsci
LIBS += -LC:\Temp\AcfPublic\3rdParty\QScintilla/Lib/$COMPILER_DIR -lQScintilla

