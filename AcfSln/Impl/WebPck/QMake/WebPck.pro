TARGET = WebPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)

LIBS += -L../../../Lib/$$COMPILER_DIR -liweb

include(../../../../Acf/Config/QMake/AcfStd.pri)

