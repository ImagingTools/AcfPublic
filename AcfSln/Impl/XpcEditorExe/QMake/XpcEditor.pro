TARGET = XpcEditor

include(../../../../Acf/Config/QMake/ApplicationConfig.pri)
include(../../../../Acf/Config/QMake/QtBaseConfig.pri)

INCLUDEPATH += ../../../Include
INCLUDEPATH += ../../../Impl

RESOURCES += $$_PRO_FILE_PWD_/../*.qrc

LIBS += -L../../../Lib/$$COMPILER_DIR -licmpstr -lAcfSlnLoc
LIBS += -lAcfLoc

HEADERS =

win32-msvc*{
	QMAKE_CXXFLAGS += /wd4264
}

QT += xml

ARXC_CONFIG = ../../../Config/Core.xpc
ARXC_FILES += ../*.arx
ARXC_OUTDIR = $$AUXINCLUDEPATH/GeneratedFiles/$$TARGET

mac{
	ICON += ../Mac/XpcEditor.icns
	QMAKE_INFO_PLIST = ../Mac/Info.plist
}


include(../../../../Acf/Config/QMake/CustomBuild.pri)
include(../../../../Acf/Config/QMake/AcfQt.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)
