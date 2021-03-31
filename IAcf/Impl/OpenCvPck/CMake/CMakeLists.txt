project(OpenCvPck LANGUAGES CXX)

link_directories($ENV{OPENCVDIR_3_3_1}/lib/${TARGETNAME})

#include(${ACFDIR}/Config/CMake/QtBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/ComponentConfig.cmake)
#include(${ACFDIR}/Config/CMake/AcfQt.cmake)
include(${ACFDIR}/Config/CMake/AcfStd.cmake)
include(../../../Config/CMake/OpenCV_3_3_1.cmake)

#target_link_directories(${PROJECT_NAME} PUBLIC ../../../../AcfSln/Lib/${TARGETNAME})
#link_directories(../../../../AcfSln/Lib/${TARGETNAME})
target_link_libraries(${PROJECT_NAME} iblob imeas iipr icalib iedge iinsp )

#target_link_directories(${PROJECT_NAME} PUBLIC ../../../Lib/${TARGETNAME})
link_directories(../../../Lib/${TARGETNAME})
target_link_libraries(${PROJECT_NAME} iocv)

qt5_use_modules(${PROJECT_NAME} Widgets Gui)
