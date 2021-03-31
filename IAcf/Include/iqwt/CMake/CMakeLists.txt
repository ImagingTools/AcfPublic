project(iqwt LANGUAGES CXX)

#link_libraries(qwtreth)

link_directories($ENV{QWTDIR_6_1_2}/Lib/${TARGETNAME})

#include(${ACFDIR}/Config/CMake/QtGuiBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/StaticConfig.cmake)
include(../../../Config/CMake/Qwt.cmake)

#qt5_use_modules(${PROJECT_NAME} Widgets Gui)
#include_directories("$ENV{QWTDIR_6_1_2}/src")
#INCLUDEPATH += $(QWTDIR_6_1_2)/src

#target_link_directories(${PROJECT_NAME} PUBLIC $ENV{QWTDIR_6_1_2}/Lib/${TARGETNAME})
#target_link_libraries(${PROJECT_NAME} qwt)

qt5_use_modules(${PROJECT_NAME} Core Widgets Gui)
