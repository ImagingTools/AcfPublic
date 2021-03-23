project(iqwt LANGUAGES CXX)

include(${ACFDIR}/Config/CMake/QtGuiBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/StaticConfig.cmake)

include_directories("$ENV{QWTDIR_6_1_2}/src")
target_link_directories(${PROJECT_NAME} PUBLIC $ENV{QWTDIR_6_1_2}/Lib/${TARGETNAME})
target_link_libraries(${PROJECT_NAME} -lqwt)

