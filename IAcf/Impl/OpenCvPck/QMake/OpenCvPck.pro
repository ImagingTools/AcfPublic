include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

TARGET = OpenCvPck

INCLUDEPATH += ../../../../AcfSln/Include
INCLUDEPATH += $(OPENCVDIR_3_3_0)/Include

#LIBS += -L../../../../Acf/Lib/$$COMPILER_DIR -lAcfStd -lAcfQt
LIBS += -L../../../../AcfSln/Lib/$$COMPILER_DIR -liblob -limeas -liipr
LIBS += -L../../../Lib/$$COMPILER_DIR -liocv
LIBS += -L$(OPENCVDIR_3_3_0)/lib/$$COMPILER_DIR


CONFIG(release, debug|release){
	LIBS += -lopencv_imgproc330 -lopencv_highgui330 -lopencv_core330 -lopencv_videoio330
}

CONFIG(debug, debug|release){
	LIBS +=-lopencv_imgproc330d -lopencv_highgui330d -lopencv_core330d -lopencv_videoio330d
}
