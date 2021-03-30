project(WinPck LANGUAGES CXX)

include(${ACFDIR}/Config/CMake/QtBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/ComponentConfig.cmake)
include(${ACFDIR}/Config/CMake/AcfStd.cmake)

#target_link_directories(${PROJECT_NAME} PUBLIC ../../../Lib/${TARGETNAME})
link_directories(../../../Lib/${TARGETNAME})
target_link_libraries(${PROJECT_NAME} iwin)
