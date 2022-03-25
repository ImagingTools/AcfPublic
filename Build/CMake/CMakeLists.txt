cmake_minimum_required(VERSION 3.1.0)
#cmake_minimum_required(VERSION 3.13.0)

project(AcfAll)

if(DEFINED ENV{QTDIR})
	set(CMAKE_PREFIX_PATH $ENV{QTDIR})
endif()

set(ACFDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf")
set(ACFSLNDIR "${CMAKE_CURRENT_LIST_DIR}../../AcfSln")
set(CONFIGSLN_DIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Config")

include("${ACFDIR}/Config/CMake/ProjectRoot.cmake")

get_target_name(TARGETNAME)

set(ACFLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf/Lib/${CMAKE_BUILD_TYPE}${TARGETNAME}")
set(ACFSLNLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Lib/${CMAKE_BUILD_TYPE}${TARGETNAME}")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../Acf/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../Acf/AuxInclude/Qt${QT_VERSION_MAJOR}_${TARGETNAME}")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/AuxInclude/Qt${QT_VERSION_MAJOR}_${TARGETNAME}")
if(NOT UNIX)
    add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../IAcf/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../IAcf/AuxInclude/Qt${QT_VERSION_MAJOR}_${TARGETNAME}")
endif()
