TARGET = ProcessingGuiPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)

QT += xml

include(../../../../Acf/Config/QMake/AcfStd.pri)
include(../../../../Acf/Config/QMake/AcfQt.pri)

LIBS += -L../../../Lib/$$COMPILER_DIR -liprocgui -liproc

