cmake_minimum_required(VERSION 3.1.0)
#cmake_minimum_required(VERSION 3.13.0)

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
	set(BUILDDIR "${CMAKE_CURRENT_LIST_DIR}/../..")
endif()

message(TARGETNAME ${TARGETNAME})

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../Acf/Build/CMake/" "${BUILDDIR}/Acf/AuxInclude/${TARGETNAME}")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Build/CMake/" "${BUILDDIR}/AcfSln/AuxInclude/${TARGETNAME}")

add_dependencies(AcfSlnLoc Acf)

if(NOT DEFINED USE_IACF OR USE_IACF)
	add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../IAcf/Build/CMake/" "${BUILDDIR}/IAcf/AuxInclude/${TARGETNAME}")
endif()
