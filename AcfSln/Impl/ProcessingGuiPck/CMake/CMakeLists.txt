project(ProcessingGuiPck LANGUAGES CXX)

include(${ACFDIR}/Config/CMake/QtBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/ComponentConfig.cmake)
include(${ACFDIR}/Config/CMake/AcfQt.cmake)
include(${ACFDIR}/Config/CMake/AcfStd.cmake)

acf_link_libraries(${PROJECT_NAME} iprocgui)
