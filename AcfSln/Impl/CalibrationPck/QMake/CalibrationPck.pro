TARGET = CalibrationPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)

LIBS += -L../../../Lib/$$COMPILER_DIR -licalib

include(../../../../Acf/Config/QMake/AcfStd.pri)
