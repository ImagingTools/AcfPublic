include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

TARGET = FfMpegPck

INCLUDEPATH += C:\Temp\AcfSln/Include
INCLUDEPATH += C:\Temp\AcfPublic\3rdParty\FFMpeg\20121010/include C:\Temp\AcfPublic\3rdParty\FFMpeg\20121010/msinttypes

LIBS += -LC:\Temp\AcfSln/Lib/$COMPILER_DIR -licam -limeas
LIBS += -L../../../Lib/$COMPILER_DIR -lilibav
LIBS += -LC:\Temp\AcfPublic\3rdParty\FFMpeg\20121010/lib -lswscale -lavdevice -lavformat -lavcodec -lavutil
