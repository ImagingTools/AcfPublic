TARGET = HotfolderPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)

LIBS += -L../../../Lib/$$COMPILER_DIR -lihotf -lifileproc -liproc

include(../../../../Acf/Config/QMake/AcfStd.pri)
