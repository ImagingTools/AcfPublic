TARGET = FfMpegPck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

INCLUDEPATH += ../../../../AcfSln/Include
INCLUDEPATH += $(FFMPEGDIR_20121010)/include $(FFMPEGDIR_20121010)/msinttypes

LIBS += -L../../../../AcfSln/Lib/$$COMPILER_DIR -licam -limeas
LIBS += -L../../../Lib/$$COMPILER_DIR -lilibav
LIBS += -L$(FFMPEGDIR_20121010)/lib -lswscale -lavdevice -lavformat -lavcodec -lavutil

