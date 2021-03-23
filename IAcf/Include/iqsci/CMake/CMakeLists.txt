project(iqsci LANGUAGES CXX)

include(${ACFDIR}/Config/CMake/QtGuiBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/StaticConfig.cmake)

include_directories("$ENV{QSCINTILLA}/Include")
include_directories("$ENV{QSCINTILLA}/Qt4Qt5")

