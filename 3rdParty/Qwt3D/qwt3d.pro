TEMPLATE = lib
TARGET = qwt3dlib

QT += gui core opengl

CONFIG += staticlib

INCLUDEPATH += Include Include/3rdparty/gl2ps

HEADERS += $$files(Include/*.h) $$files(Include/3rdparty/gl2ps/*.h)
SOURCES += $$files(Src/*.cpp) $$files(Include/3rdparty/gl2ps/*.c)
RESOURCES += Src/Qwt3d.qrc

win32-g++{
    COMPILER_NAME = MinGW
}

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

DESTDIR = ./Lib/$$COMPILER_DIR

 

