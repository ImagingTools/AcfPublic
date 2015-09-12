TARGET = iservice

include(../../../../Acf/Config/QMake/StaticConfig.pri)
include(../../../../Acf/Config/QMake/QtGuiBaseConfig.pri)

win32-msvc*{
	HEADERS = ../qtservice.h ../qtservice_win.h ../qtservicestarter.h ../CServiceApplicationComp.h
	SOURCES = ../qtservice.cpp ../qtservice_win.cpp ../qtservicestarter.cpp
	SOURCES += ../CServiceApplicationComp.cpp
}
else
{
SOURCES = ../CServiceApplicationComp.cpp
HEADERS = ../CServiceApplicationComp.h
}

