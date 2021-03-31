cmake_minimum_required(VERSION 3.1.0)
#cmake_minimum_required(VERSION 3.13.0)

project(AcfAll)

set(QT_DEFAULT_MAJOR_VERSION 5)
message("CMAKE_VERSION " ${CMAKE_VERSION})
#if($ENV{QTDIR})
#	set(CMAKE_PREFIX_PATH $ENV{QTDIR})
	message("set CMAKE_PREFIX_PATH " ${CMAKE_PREFIX_PATH})
	message("Qt5Core_DIR " ${Qt5Core_DIR})
#endif()

set(ACFDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf")
set(ACFSLNDIR "${CMAKE_CURRENT_LIST_DIR}../../AcfSln")

set(CONFIGSLN_DIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Config")

#set(DEPENDS_OF_ACF TRUE)

include("${ACFDIR}/Config/CMake/Macro.cmake")

message("ACFDIR: " ${ACFDIR})
message("ACFSLNDIR: " ${ACFSLNDIR})

get_target_name(TARGETNAME)

set(ACFLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf/Lib/${TARGETNAME}")
set(ACFSLNLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Lib/${TARGETNAME}")

#add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../Acf/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../Acf/AuxInclude/${TARGETNAME}")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/AuxInclude/${TARGETNAME}")
#add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../IAcf/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../IAcf/AuxInclude/${TARGETNAME}")

