cmake_minimum_required(VERSION 3.1.0)
#cmake_minimum_required(VERSION 3.13.0)

project(AcfAll)

if(DEFINED ENV{QTDIR})
	set(CMAKE_PREFIX_PATH $ENV{QTDIR})
endif()

if (MSVC_IDE)
	set(CMAKE_BUILD_TYPE $<$<CONFIG:DEBUG>:Debug>$<$<CONFIG:RELEASE>:Release>$<$<CONFIG:MINSIZEREL>:MinSizeRel>$<$<CONFIG:RELWITHDEBINFO>:RelWithDebInfo>)
endif()

set(ACFDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf")
set(ACFSLNDIR "${CMAKE_CURRENT_LIST_DIR}../../AcfSln")
set(CONFIGSLN_DIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Config")

include("${ACFDIR}/Config/CMake/ProjectRoot.cmake")

get_target_name(TARGETNAME)

set(ACFLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf/Lib/${CMAKE_BUILD_TYPE}_${TARGETNAME}")
set(ACFSLNLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Lib/${CMAKE_BUILD_TYPE}_${TARGETNAME}")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../Acf/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../Acf/AuxInclude/${TARGETNAME}")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/AuxInclude/${TARGETNAME}")

if(NOT DEFINED USE_IACF OR USE_IACF)
	add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../IAcf/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../IAcf/AuxInclude/${TARGETNAME}")
endif()
