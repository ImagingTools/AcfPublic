include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

TARGET = OpenCvPck

INCLUDEPATH += ../../../../AcfSln/Include
INCLUDEPATH += $(OPENCVDIR_2_4_10)/Include

#LIBS += -L../../../../Acf/Lib/$$COMPILER_DIR -lAcfStd -lAcfQt
LIBS += -L../../../../AcfSln/Lib/$$COMPILER_DIR -liblob -limeas -liipr
LIBS += -L../../../Lib/$$COMPILER_DIR -liocv
LIBS += -L$(OPENCVDIR_2_4_10)/lib/$$COMPILER_DIR -lopencv_imgproc2410 -lopencv_highgui2410 -lopencv_core2410

