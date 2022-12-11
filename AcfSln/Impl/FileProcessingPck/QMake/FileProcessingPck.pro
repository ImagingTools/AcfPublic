TARGET = FileProcessingPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)

LIBS += -L../../../Lib/$$COMPILER_DIR -lifileproc -liproc

include(../../../../Acf/Config/QMake/AcfStd.pri)

