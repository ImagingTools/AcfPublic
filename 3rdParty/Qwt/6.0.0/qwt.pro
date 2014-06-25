include(../../../Acf/Config/QMake/QtGuiBaseConfig.pri)


TEMPLATE = lib
TARGET = qwt

COMPILER_NAME = QMake

win32-msvc*{
	COMPILER_NAME = VC

	win32-msvc2003{
		COMPILER_NAME = VC7
	}
	win32-msvc2005{
		COMPILER_NAME = VC8
	}
	win32-msvc2008{
		COMPILER_NAME = VC9
	}
        win32-msvc2010{
                COMPILER_NAME = VC10
        }
        win32-msvc2012{
                COMPILER_NAME = VC11
        }
        win32-msvc2013{
                COMPILER_NAME = VC12
        }
}

CONFIG(debug, debug|release){
        COMPILER_DIR = "Debug$$COMPILER_NAME"_"Qt$$QT_MAJOR_VERSION"
}
CONFIG(release, debug|release){
        COMPILER_DIR = "Release$$COMPILER_NAME"_"Qt$$QT_MAJOR_VERSION"
}

DESTDIR = $$PWD/Lib/$$COMPILER_DIR
CONFIG += staticlib

HEADERS += $$PWD/Include/*.h
SOURCES += $$PWD/Include/*.cpp
 
QT += gui core svg printsupport

