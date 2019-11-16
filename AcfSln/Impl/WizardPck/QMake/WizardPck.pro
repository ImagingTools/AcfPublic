TARGET = WizardPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)

LIBS += -L../../../Lib/$$COMPILER_DIR -liwiz -liproc

include(../../../../Acf/Config/QMake/AcfStd.pri)

