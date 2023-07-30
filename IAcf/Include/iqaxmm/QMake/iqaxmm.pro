TARGET = iqaxmm

include(../../../../Acf/Config/QMake/StaticConfig.pri)

QT += multimedia axcontainer

INCLUDEPATH += ../../../../AcfSln/Include

HEADERS += ../Wrapped/axvlc.h
SOURCES += ../Wrapped/axvlc.cpp

