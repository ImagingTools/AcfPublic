greaterThan(QT_MAJOR_VERSION, 4): QT *= widgets


CONFIG(release,debug|release){
    UI_DIR = release
}

CONFIG(debug,debug|release){
    UI_DIR = debug
}

unix {
    LIB_SUFFIX = so
}



win32 {
    LIB_SUFFIX = lib
}


COMPILER_NAME = QMake
PLATFORM_NAME = Unix

win32-msvc*{
	COMPILER_NAME = VC
	PLATFORM_NAME = Win
	QMAKE_CXXFLAGS += /wd4127 /wd4250 /wd4347 /wd4355 /wd4365 /wd4505 /wd4510 /wd4511 /wd4512 /wd4548 /wd4571 /wd4619 /wd4625 /wd4626 /wd4640 /wd4702 /wd4710 /wd4820 /wd4826
	QMAKE_CXXFLAGS_WARN_ON = -W4
	QMAKE_CXXFLAGS += /MP /openmp- /fp:fast /arch:SSE2

	win32-msvc2005{
		COMPILER_NAME = VC8
	}
	win32-msvc2008{
		COMPILER_NAME = VC9
	}
	win32-msvc2010{
		QMAKE_CXXFLAGS += /wd4996
		COMPILER_NAME = VC10
	}
	win32-msvc2012{
		QMAKE_CXXFLAGS += /wd4996
		COMPILER_NAME = VC11
	}
	win32-msvc2013{
	    	QMAKE_CXXFLAGS += /wd4996 /Qpar /Gy /Gw /FS
		QMAKE_LFLAGS += /LTCG:PGO
		COMPILER_NAME = VC12
	}

	contains(QMAKE_HOST.arch, x86_64){
		PLATFORM_NAME = Win64
	}
	else{
		PLATFORM_NAME = Win32
	}
}

LIBRARY_SUFIX =

CONFIG(debug, debug|release){
        COMPILER_DIR = Debug$$COMPILER_NAME
}
CONFIG(release, debug|release){
        COMPILER_DIR = Release$$COMPILER_NAME
        CONFIG += sse2
}

