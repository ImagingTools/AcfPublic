message(${CMAKE_CURRENT_LIST_DIR})
cmake_minimum_required(VERSION 3.1.0)

project(IAcf)

set(QT_DEFAULT_MAJOR_VERSION 5)

if(NOT DEFINED ${ACFDIR})
	message("NOT ACFDIR " "${ACFDIR}")
	if(DEFINED ENV{ACFDIR})
		set(ACFDIR $ENV{ACFDIR})
	else()
		set(ACFDIR "${CMAKE_CURRENT_LIST_DIR}/../../../Acf")
	endif()
endif()

if(NOT DEFINED ${ACFSLNDIR})
	message("NOT ACFDIR " "${ACFSLNDIR}")
	if(DEFINED ENV{ACFSLNDIR})
		set(ACFSLNDIR $ENV{ACFSLNDIR})
	else()
		set(ACFSLNDIR "${CMAKE_CURRENT_LIST_DIR}/../../../Acf")
	endif()
endif()

set(IACFDIR "${CMAKE_CURRENT_LIST_DIR}/../../../AcfSln")

include(${ACFDIR}/Config/CMake/Macro.cmake)


get_target_name(TARGETNAME)

include_directories("${ACFDIR}/Include")
include_directories("${ACFDIR}/Impl")

set(INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Include")
set(IMPL_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Impl")

set(AUX_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../AuxInclude/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}/GeneratedFiles")

include_directories("${CMAKE_CURRENT_LIST_DIR}/../../AuxInclude/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
include_directories("${CMAKE_CURRENT_LIST_DIR}/../../../Acf/AuxInclude/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")

message("IACF AUX_INCLUDE_DIR " "${AUX_INCLUDE_DIR}")

# Include

add_subdirectory("${INCLUDE_DIR}/iocv/CMake" "${AUX_INCLUDE_DIR}/iocv")
add_subdirectory("${INCLUDE_DIR}/iqaxmm/CMake" "${AUX_INCLUDE_DIR}/iqaxmm")
add_subdirectory("${INCLUDE_DIR}/iqwt/CMake" "${AUX_INCLUDE_DIR}/iqwt")
add_subdirectory("${INCLUDE_DIR}/iqwt3d/CMake" "${AUX_INCLUDE_DIR}/iqwt3d")
add_subdirectory("${INCLUDE_DIR}/iwin/CMake" "${AUX_INCLUDE_DIR}/iwin")
add_subdirectory("${INCLUDE_DIR}/ilibav/CMake" "${AUX_INCLUDE_DIR}/ilibav")
add_subdirectory("${INCLUDE_DIR}/iqsci/CMake" "${AUX_INCLUDE_DIR}/iqsci")
add_subdirectory("${INCLUDE_DIR}/idc1394/CMake" "${AUX_INCLUDE_DIR}/idc1394")

# Impl

add_subdirectory("${IMPL_DIR}/IacfLoc/CMake" "${AUX_INCLUDE_DIR}/IacfLoc")
add_subdirectory("${IMPL_DIR}/OpenCvPck/CMake" "${AUX_INCLUDE_DIR}/OpenCvPck")
add_subdirectory("${IMPL_DIR}/QwtPck/CMake" "${AUX_INCLUDE_DIR}/QwtPck")
add_subdirectory("${IMPL_DIR}/WinPck/CMake" "${AUX_INCLUDE_DIR}/WinPck")
add_subdirectory("${IMPL_DIR}/FfMpegPck/CMake" "${AUX_INCLUDE_DIR}/FfMpegPck")
add_subdirectory("${IMPL_DIR}/QaxPck/CMake" "${AUX_INCLUDE_DIR}/QaxPck")
add_subdirectory("${IMPL_DIR}/QsciPck/CMake" "${AUX_INCLUDE_DIR}/QsciPck")
add_subdirectory("${IMPL_DIR}/Dc1394Pck/CMake" "${AUX_INCLUDE_DIR}/Dc1394Pck")


#set(INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Include")
#set(IMPL_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Impl")

#set(LIB_DIR "$ENV{ACFDIR}/Lib/${TARGETNAME}")

#set(AUX_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../AuxInclude/${TARGETNAME}")


#list(APPEND DEPENDSY_SUBDIRS_INCLUDE
#"iocv"
#"iqaxmm"
#"iqwt"
#"iqwt3d"
#"iwin"
#"ilibav"
#"iqsci"
#"idc1394"
#)

#list(APPEND DEPENDSY_SUBDIRS_IMPL
#"IacfLoc"
#"OpenCvPck"
#"QwtPck"
#"WinPck"
#"FfMpegPck"
#"QaxPck"
#"QsciPck"
#"Dc1394Pck"
#)

#list(APPEND LIB_LIST "")

#FOREACH(SUBDIR ${DEPENDSY_SUBDIRS_INCLUDE})
#        set(PROJECT_NAME ${SUBDIR})
#        set(PROJECT_DIR "${INCLUDE_DIR}/${PROJECT_NAME}")
#        set(SOURCES_DIR "${INCLUDE_DIR}/${PROJECT_NAME}/CMake")
#        set(BINARY_DIR "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
#        add_subdirectory(${SOURCES_DIR} ${BINARY_DIR})
#        list(APPEND LIB_DIRS "${LIB_DIR}/${PROJECT_NAME}")
#        list(APPEND LIB_LIST ${PROJECT_NAME})
#ENDFOREACH()
##
#FOREACH(SUBDIR ${DEPENDSY_SUBDIRS_IMPL})
#        set(PROJECT_NAME ${SUBDIR})
#        set(PROJECT_DIR "${IMPL_DIR}/${PROJECT_NAME}")
#        set(SOURCES_DIR "${IMPL_DIR}/${PROJECT_NAME}/CMake")
#        set(BINARY_DIR "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
#        list(APPEND LIB_DIRS "${LIB_DIR}/${PROJECT_NAME}")
#        add_subdirectory(${SOURCES_DIR} ${BINARY_DIR})
#ENDFOREACH()

