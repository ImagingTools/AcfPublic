TARGET            = qwtplot3d
TEMPLATE          = lib
DESTDIR      	  = ../lib
CONFIG           += qt warn_on thread static #release
QT               += opengl
#QT += openglwidgets
#CONFIG += staticlib

SOURCES           = *.cpp

# MOCs will be generated from
HEADERS           = ../include/qwt3d_appearance.h \
                    ../include/qwt3d_autoscaler.h \
		    ../include/qwt3d_axis.h \
		    ../include/qwt3d_color.h \
		    ../include/qwt3d_color_std.h \
		    ../include/qwt3d_colorlegend.h \
		    ../include/qwt3d_coordsys.h \
		    ../include/qwt3d_curveplot.h \
		    ../include/qwt3d_data.h \
		    ../include/qwt3d_drawable.h \
		    ../include/qwt3d_enrichment.h \
		    ../include/qwt3d_enrichment_std.h \
		    ../include/qwt3d_extglwidget.h \
		    ../include/qwt3d_function.h \
		    ../include/qwt3d_global.h \
		    ../include/qwt3d_graphplot.h \
		    ../include/qwt3d_gridmapping.h \
		    ../include/qwt3d_gridplot.h \
		    ../include/qwt3d_helper.h \
		    ../include/qwt3d_io.h \
		    ../include/qwt3d_io_reader.h \
		    ../include/qwt3d_label.h \
		    ../include/qwt3d_mapping.h \
		    ../include/qwt3d_meshplot.h \
		    ../include/qwt3d_openglhelper.h \
		    ../include/qwt3d_parametricsurface.h \
		    ../include/qwt3d_plot3d.h \
		    ../include/qwt3d_portability.h \
		    ../include/qwt3d_scale.h \
		    ../include/qwt3d_surfaceplot.h \
		    ../include/qwt3d_types.h \
		    ../include/qwt3d_valueptr.h \
		    ../include/qwt3d_volumeplot.h
#HEADERS           += ../include/*.h

INCLUDEPATH       = ../include

win32 {
    QMAKE_CXXFLAGS += -MP
    QMAKE_CXXFLAGS += $$QMAKE_CFLAGS_STL
    QMAKE_CXXFLAGS_RELEASE += /fp:fast /arch:SSE2
}

linux-g++:QMAKE_CXXFLAGS += -fno-exceptions

unix:VERSION = 0.3.2

MOC_DIR           = tmp
OBJECTS_DIR       = tmp
