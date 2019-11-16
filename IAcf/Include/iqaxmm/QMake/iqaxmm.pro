TARGET = iqaxmm

include(../../../../Acf/Config/QMake/StaticConfig.pri)

QT += multimedia axcontainer

INCLUDEPATH += ../../../../AcfSln/Include

HEADERS += ../Wrapped/*.h
SOURCES += ../Wrapped/*.cpp

