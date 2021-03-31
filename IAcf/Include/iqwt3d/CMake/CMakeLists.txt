project(iqwt3d LANGUAGES CXX)

link_directories($ENV{QWT3DDIR_0_3_1}/Lib/${TARGETNAME})

include(${ACFDIR}/Config/CMake/QtGuiBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/StaticConfig.cmake)
include(../../../Config/CMake/Qwt3d.cmake)


#include_directories("$ENV{QWT3DDIR_0_3_1}/Include")
#target_link_directories(${PROJECT_NAME} PUBLIC $ENV{QWT3DDIR_0_3_1}/Lib/${TARGETNAME})
#target_link_libraries(${PROJECT_NAME} -lqwt3d)
#qt5_use_modules(${PROJECT_NAME} Widgets Gui)

qt5_use_modules(${PROJECT_NAME} Core Widgets OpenGL Gui)
