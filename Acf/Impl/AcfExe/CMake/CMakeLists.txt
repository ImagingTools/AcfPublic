project(Acf LANGUAGES CXX)

include(${ACFDIR}/Config/CMake/ApplicationConfig.cmake)
include(${ACFDIR}/Config/CMake/AcfQt.cmake)
include(${ACFDIR}/Config/CMake/AcfStd.cmake)

qt5_use_modules(${PROJECT_NAME} Xml)
