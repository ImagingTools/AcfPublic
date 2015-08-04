TARGET = FilePck

include(../../../Config/QMake/ComponentConfig.pri)

QT += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../../../Config/QMake/AcfStd.pri)

LIBS += -LC:\Qt\Qt-5.3.1-VS2008/lib -lQt5Concurrent

