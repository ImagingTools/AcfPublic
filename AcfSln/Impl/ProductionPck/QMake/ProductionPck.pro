TARGET = ProductionPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)

LIBS += -L../../../Lib/$$COMPILER_DIR -liprod

include(../../../../Acf/Config/QMake/AcfStd.pri)
