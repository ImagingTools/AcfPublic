project(iqwt LANGUAGES CXX)


#link_directories($ENV{QWTDIR_6_2_0}/lib/${TARGETNAME})

include(${ACFDIR}/Config/CMake/StaticConfig.cmake)
include(../../../Config/CMake/Qwt.cmake)

#qt5_use_modules(${PROJECT_NAME} Core Widgets Gui)
