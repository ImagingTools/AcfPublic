TARGET = Dc1394Pck

include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

INCLUDEPATH += ../../../Include
INCLUDEPATH += ../../../../AcfSln/Include
INCLUDEPATH += $(LIBDC1394_2_2_0)

LIBS += -L../../../Lib/$$COMPILER_DIR -lidc1394

macx{
	LIBS += -L../../../../AcfSln/Lib/$$COMPILER_DIR -licam
	LIBS += -L$(LIBDC1394_2_2_0)/lib -ldc1394
}

