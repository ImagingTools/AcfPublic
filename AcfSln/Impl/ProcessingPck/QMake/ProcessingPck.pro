include(../../../../Acf/Config/QMake/ComponentConfig.pri)

TARGET = ProcessingPck

LIBS += -L../../../Lib/$COMPILER_DIR -liproc

include(../../../../Acf/Config/QMake/AcfStd.pri)
