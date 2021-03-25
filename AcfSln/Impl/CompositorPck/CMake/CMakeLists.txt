project(CompositorPck LANGUAGES CXX)

include(${ACFDIR}/Config/CMake/QtBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/ComponentConfig.cmake)
include(${ACFDIR}/Config/CMake/AcfQt.cmake)
include(${ACFDIR}/Config/CMake/AcfStd.cmake)

acf_link_libraries(${PROJECT_NAME} icmpstr)
qt5_use_modules(${PROJECT_NAME} PrintSupport)
