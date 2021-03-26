project(OpenCvPck LANGUAGES CXX)

include(${ACFDIR}/Config/CMake/QtBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/ComponentConfig.cmake)
#include(${ACFDIR}/Config/CMake/AcfQt.cmake)
include(${ACFDIR}/Config/CMake/AcfStd.cmake)
include(../../../Config/CMake/OpenCV_3_3_1.cmake)

target_link_directories(${PROJECT_NAME} PUBLIC ../../../../AcfSln/Lib/${TARGETNAME})
acf_link_libraries(${PROJECT_NAME} iblob imeas iipr icalib iedge iinsp )

target_link_directories(${PROJECT_NAME} PUBLIC ../../../Lib/${TARGETNAME})
acf_link_libraries(${PROJECT_NAME} iocv)

qt5_use_modules(${PROJECT_NAME} Widgets Gui)
