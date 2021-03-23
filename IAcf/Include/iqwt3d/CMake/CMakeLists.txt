project(iqwt3d LANGUAGES CXX)

include(${ACFDIR}/Config/CMake/QtGuiBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/StaticConfig.cmake)

include_directories("$ENV{QWT3DDIR_0_3_1}/Include")
target_link_directories(${PROJECT_NAME} PUBLIC $ENV{QWT3DDIR_0_3_1}/Lib/${TARGETNAME})
target_link_libraries(${PROJECT_NAME} -lqwt3d)

