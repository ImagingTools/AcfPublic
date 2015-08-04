include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

TARGET = Dc1394Pck

INCLUDEPATH += ../../../Include
INCLUDEPATH += C:\Temp\AcfSln/Include
INCLUDEPATH += C:\Temp\AcfPublic\3rdParty\libdc1394\2.2.0

LIBS += -L../../../Lib/$$COMPILER_DIR -lidc1394

macx{
	LIBS += -LC:\Temp\AcfSln/Lib/$$COMPILER_DIR -licam
	LIBS += -LC:\Temp\AcfPublic\3rdParty\libdc1394\2.2.0/lib -ldc1394
}
