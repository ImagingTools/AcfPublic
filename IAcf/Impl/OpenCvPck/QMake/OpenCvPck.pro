include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

TARGET = OpenCvPck

INCLUDEPATH += C:\Temp\AcfSln/Include
INCLUDEPATH += C:\Temp\AcfPublic\3rdParty\OpenCV\2.4.10/Include

#LIBS += -LC:\Temp\Acf/Lib/$$COMPILER_DIR -lAcfStd -lAcfQt
LIBS += -LC:\Temp\AcfSln/Lib/$$COMPILER_DIR -liblob -limeas -liipr
LIBS += -L../../../Lib/$$COMPILER_DIR -liocv
LIBS += -LC:\Temp\AcfPublic\3rdParty\OpenCV\2.4.10/lib/$$COMPILER_DIR -lopencv_imgproc2410 -lopencv_highgui2410 -lopencv_core2410

