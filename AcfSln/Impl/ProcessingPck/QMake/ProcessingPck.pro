TARGET = ProcessingPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)

LIBS += -L../../../Lib/$$COMPILER_DIR -liproc

include(../../../../Acf/Config/QMake/AcfStd.pri)
