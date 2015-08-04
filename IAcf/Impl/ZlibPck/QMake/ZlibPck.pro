include(../../../../Acf/Config/QMake/ComponentConfig.pri)
include(../../../../Acf/Config/QMake/AcfStd.pri)

TARGET = ZlibPck

INCLUDEPATH += ../../../Include
INCLUDEPATH += "C:\Temp\AcfPublic\3rdParty\zlib/include" 

LIBS += -L../../../Lib/$$COMPILER_DIR -lizlib
LIBS += -LC:\Temp\AcfPublic\3rdParty\zlib/lib -lzlib

