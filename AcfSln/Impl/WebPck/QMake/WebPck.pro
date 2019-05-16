include(../../../../Acf/Config/QMake/ComponentConfig.pri)

TARGET = WebPck

LIBS += -L../../../Lib/$$COMPILER_DIR -liweb

include(../../../../Acf/Config/QMake/AcfStd.pri)
