include(../../../../Acf/Config/QMake/StaticConfig.pri)

TARGET = iqaxmm
QT += multimedia axcontainer

INCLUDEPATH += ../../../../AcfSln/Include

HEADERS += ../Wrapped/*.h
SOURCES += ../Wrapped/*.cpp

