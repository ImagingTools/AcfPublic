TEMPLATE = lib
TARGET = qwt3dlib

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
}

CONFIG(debug, debug|release){
        COMPILER_DIR = "Debug$$COMPILER_NAME"_"Qt$$QT_MAJOR_VERSION"
}
CONFIG(release, debug|release){
        COMPILER_DIR = "Release$$COMPILER_NAME"_"Qt$$QT_MAJOR_VERSION"
}

DESTDIR = ./Lib/$$COMPILER_DIR
CONFIG += staticlib

INCLUDEPATH += Include Include/3rdparty/gl2ps

HEADERS += Include/*.h Include/3rdparty/gl2ps/*.h
SOURCES += Src/*.cpp Include/3rdparty/gl2ps/*.c
 
QT += gui core opengl

