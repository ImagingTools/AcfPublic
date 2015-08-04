include(../../../../Acf/Config/QMake/ComponentConfig.pri)

TARGET = WizardPck

LIBS += -L../../../Lib/$$COMPILER_DIR -liwiz -liproc

include(../../../../Acf/Config/QMake/AcfStd.pri)
