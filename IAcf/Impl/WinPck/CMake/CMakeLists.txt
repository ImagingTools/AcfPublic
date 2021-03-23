project(WinPck LANGUAGES CXX)

include(${ACFDIR}/Config/CMake/QtBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/ComponentConfig.cmake)
include(${ACFDIR}/Config/CMake/AcfQt.cmake)
include(${ACFDIR}/Config/CMake/AcfStd.cmake)

include_directories("${PROJECT_SOURCE_DIR}/../../../../AcfSln/Include")
target_link_libraries(${PROJECT_NAME} -lqwt3d)
