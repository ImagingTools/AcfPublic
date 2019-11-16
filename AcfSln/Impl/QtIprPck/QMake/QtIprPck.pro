TARGET = QtIprPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)

LIBS += -L../../../Lib/$$COMPILER_DIR -liqtipr -liipr -limeas

include(../../../../Acf/Config/QMake/AcfQt.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

