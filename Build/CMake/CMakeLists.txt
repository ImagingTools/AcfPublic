cmake_minimum_required(VERSION 3.26)

project(AcfAll)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core)

if(DEFINED ENV{QTDIR})
	list(APPEND CMAKE_PREFIX_PATH $ENV{QTDIR})
endif()

if (MSVC_IDE)
	set(CMAKE_BUILD_TYPE $<$<CONFIG:DEBUG>:Debug>$<$<CONFIG:RELEASE>:Release>$<$<CONFIG:MINSIZEREL>:MinSizeRel>$<$<CONFIG:RELWITHDEBINFO>:RelWithDebInfo>)
endif()

set(ACFDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf")
set(ACFSLNDIR "${CMAKE_CURRENT_LIST_DIR}../../AcfSln")
set(CONFIGSLN_DIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Config")

include("${ACFDIR}/Config/CMake/ProjectRoot.cmake")

get_target_name(TARGETNAME)

if(NOT DEFINED BUILDDIR)
	if(DEFINED ENV{ACF_OUTPUT_DIR})
		set(BUILDDIR "$ENV{ACF_OUTPUT_DIR}")
	else()
		set(BUILDDIR "${CMAKE_CURRENT_LIST_DIR}/../..")
	endif()
endif()

message("BUILDDIR: " ${BUILDDIR})

message(TARGETNAME ${TARGETNAME})

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../Acf/Build/CMake/" "${BUILDDIR}/Acf/AuxInclude/${TARGETNAME}")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Build/CMake/" "${BUILDDIR}/AcfSln/AuxInclude/${TARGETNAME}")

add_dependencies(AcfSlnLoc Acf)

if(NOT DEFINED USE_IACF OR USE_IACF)
	add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../IAcf/Build/CMake/" "${BUILDDIR}/IAcf/AuxInclude/${TARGETNAME}")
endif()
