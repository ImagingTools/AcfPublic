TARGET = AcfSlnLoc

include(..\..\..\..\Acf\Config/QMake/StaticConfig.pri)
include(..\..\..\..\Acf\Config/QMake/CustomBuild.pri)

HEADERS =
SOURCES =
ACF_TRANSLATIONS += $$_PRO_FILE_PWD_/../*.ts
GENERATED_RESOURCES += $$_PRO_FILE_PWD_/../*.qrc

include(..\..\..\..\Acf\Config/QMake/CustomBuild.pri)
