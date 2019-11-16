TARGET = QtMmPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)
include(../../../../Acf/Config/QMake/AcfQt.pri)

QT += svg phonon

LIBS += -L../../../Lib/$$COMPILER_DIR -liqtmm

