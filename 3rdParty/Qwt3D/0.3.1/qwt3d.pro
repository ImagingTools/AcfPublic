TEMPLATE = lib
TARGET = qwt3d

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
                QMAKE_CFLAGS += /FS
        }
}

CONFIG(debug, debug|release){
	COMPILER_DIR = Debug$$COMPILER_NAME
}
CONFIG(release, debug|release){
	COMPILER_DIR = Release$$COMPILER_NAME
}

greaterThan(QT_MAJOR_VERSION, 4) {
    CONFIG(debug, debug|release){
            COMPILER_DIR = "Debug$$COMPILER_NAME"_Qt5
    }
    CONFIG(release, debug|release){
            COMPILER_DIR = "Release$$COMPILER_NAME"_Qt5
    }
}

DESTDIR = $$PWD/Lib/$$COMPILER_DIR
CONFIG += staticlib

INCLUDEPATH += Include
 
QT += gui core opengl

RESOURCES += \
    Src/Qwt3d.qrc

SOURCES += \
    Src/qwt3d_appearance.cpp \
    Src/qwt3d_autoscaler.cpp \
    Src/qwt3d_axis.cpp \
    Src/qwt3d_color_std.cpp \
    Src/qwt3d_colorlegend.cpp \
    Src/qwt3d_coordsys.cpp \
    Src/qwt3d_data.cpp \
    Src/qwt3d_drawable.cpp \
    Src/qwt3d_enrichment_std.cpp \
    Src/qwt3d_extglwidget.cpp \
    Src/qwt3d_function.cpp \
    Src/qwt3d_graphplot.cpp \
    Src/qwt3d_gridmapping.cpp \
    Src/qwt3d_gridplot.cpp \
    Src/qwt3d_io.cpp \
    Src/qwt3d_io_reader.cpp \
    Src/qwt3d_label.cpp \
    Src/qwt3d_lighting.cpp \
    Src/qwt3d_meshplot.cpp \
    Src/qwt3d_parametricsurface.cpp \
    Src/qwt3d_plot3d.cpp \
    Src/qwt3d_scale.cpp \
    Src/qwt3d_surfaceplot.cpp \
    Src/qwt3d_types.cpp \
    Src/qwt3d_volumeplot.cpp

HEADERS += \
    Include/qwt3d_appearance.h \
    Include/qwt3d_autoscaler.h \
    Include/qwt3d_axis.h \
    Include/qwt3d_color.h \
    Include/qwt3d_color_std.h \
    Include/qwt3d_colorlegend.h \
    Include/qwt3d_coordsys.h \
    Include/qwt3d_data.h \
    Include/qwt3d_drawable.h \
    Include/qwt3d_enrichment.h \
    Include/qwt3d_enrichment_std.h \
    Include/qwt3d_extglwidget.h \
    Include/qwt3d_function.h \
    Include/qwt3d_global.h \
    Include/qwt3d_graphplot.h \
    Include/qwt3d_gridmapping.h \
    Include/qwt3d_gridplot.h \
    Include/qwt3d_helper.h \
    Include/qwt3d_io.h \
    Include/qwt3d_io_reader.h \
    Include/qwt3d_label.h \
    Include/qwt3d_mapping.h \
    Include/qwt3d_meshplot.h \
    Include/qwt3d_openglhelper.h \
    Include/qwt3d_parametricsurface.h \
    Include/qwt3d_plot3d.h \
    Include/qwt3d_portability.h \
    Include/qwt3d_scale.h \
    Include/qwt3d_surfaceplot.h \
    Include/qwt3d_types.h \
    Include/qwt3d_valueptr.h \
    Include/qwt3d_volumeplot.h



