message(${CMAKE_CURRENT_LIST_DIR})
cmake_minimum_required(VERSION 3.1.0)

project(Acf)

set(QT_DEFAULT_MAJOR_VERSION 5)

include("${ACFDIR}/Config/CMake/Macro.cmake")

set(INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Include")
set(IMPL_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Impl")

message(${INCLUDE_DIR})

subdirlist(INCLUDE_DIRS ${INCLUDE_DIR})
subdirlist(IMPL_DIRS ${IMPL_DIR})

get_target_name(TARGETNAME)

#set(LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Lib/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")

set(AUX_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../AuxInclude/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}/GeneratedFiles")

#set(ACFBINDIR "${CMAKE_CURRENT_LIST_DIR}/../../Bin/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
set(ACFBINDIR "${CMAKE_CURRENT_LIST_DIR}/../../Bin/${TARGETNAME}")

list(APPEND DEPENDSY_SUBDIRS_INCLUDE 
#"istd"
#"iser"
#"ilog"
#"i2d"
#"i3d"
#"iattr"
#"iimg"
#"imath"
#"icmm"
#"imod"
#"icomp"
#"idoc"
#"iprm"
#"ibase"
#"iqt"
#"ifile"
#"iqt2d"
#"iview"
#"iqtdoc"
#"iwidgets"
#"iqtgui"
#"ifilegui"
#"iloggui"
#"iqtprm"
#"ipackage"
#"itest"
)

list(APPEND DEPENDSY_SUBDIRS_IMPL 
#		"BasePck"
#		"BitmapPck"
#		"QtPck"
#		"FilePck"
#		"QtGuiPck"
#		"QtViewPck"
#		"PackagePck"
#		"FileGuiPck"
#	"ArxcExe"
#	"AcfExe"
#	"AcfLoc"
)

#list(APPEND LIB_LIST "")
#list(APPEND REPLACE_LIST "Pck" "Exe" "Loc")

include_directories(${AUX_INCLUDE_DIR}/..)


#FOREACH(SUBDIR ${DEPENDSY_SUBDIRS_INCLUDE})
##	set(PROJECT_NAME ${SUBDIR})
#		set(PROJECT_DIR "${INCLUDE_DIR}/${SUBDIR}")
#		set(SOURCES_DIR "${INCLUDE_DIR}/${SUBDIR}/CMake")
#		set(BINARY_DIR "${AUX_INCLUDE_DIR}/${SUBDIR}")
##        set(LIBRARY_OUTPUT_PATH "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
##        set(EXECUTABLE_OUTPUT_PATH "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
##        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
#	add_subdirectory(${SOURCES_DIR} ${BINARY_DIR})
##        list(APPEND LIB_DIRS "${LIB_DIR}/${PROJECT_NAME}")
##	list(APPEND LIB_LIST ${PROJECT_NAME})
#ENDFOREACH()
#
#FOREACH(SUBDIR ${DEPENDSY_SUBDIRS_IMPL})
##	set(PROJECT_NAME ${SUBDIR})
#		set(PROJECT_DIR "${IMPL_DIR}/${SUBDIR}")
#		set(SOURCES_DIR "${IMPL_DIR}/${SUBDIR}/CMake")
##        list(APPEND LIB_DIRS "${LIB_DIR}/${PROJECT_NAME}")
##        if(NOT ${PROJECT_NAME}   MATCHES ".*Loc")
##            STRING(REGEX REPLACE "([^ ]*)...$" "\\1" PROJECT_NAME ${PROJECT_NAME})
##        endif()
##		if(${PROJECT_NAME}   MATCHES ".*Exe")
##			STRING(REGEX REPLACE "([^ ]*)...$" "\\1" PROJECT_NAME ${PROJECT_NAME})
##		endif()
#message("SOURCES_DIR " ${SOURCES_DIR})
#        set(BINARY_DIR "${AUX_INCLUDE_DIR}/${SUBDIR}")
#        add_subdirectory(${SOURCES_DIR} ${BINARY_DIR})
#ENDFOREACH()


# Include

add_subdirectory("${INCLUDE_DIR}/istd/CMake" "${AUX_INCLUDE_DIR}/istd")
add_subdirectory("${INCLUDE_DIR}/iser/CMake" "${AUX_INCLUDE_DIR}/iser")
add_subdirectory("${INCLUDE_DIR}/ilog/CMake" "${AUX_INCLUDE_DIR}/ilog")
add_subdirectory("${INCLUDE_DIR}/i2d/CMake" "${AUX_INCLUDE_DIR}/i2d")
add_subdirectory("${INCLUDE_DIR}/i3d/CMake" "${AUX_INCLUDE_DIR}/i3d")

add_subdirectory("${INCLUDE_DIR}/iattr/CMake" "${AUX_INCLUDE_DIR}/iattr")
add_subdirectory("${INCLUDE_DIR}/iimg/CMake" "${AUX_INCLUDE_DIR}/iimg")
add_subdirectory("${INCLUDE_DIR}/imath/CMake" "${AUX_INCLUDE_DIR}/imath")
add_subdirectory("${INCLUDE_DIR}/icmm/CMake" "${AUX_INCLUDE_DIR}/icmm")
add_subdirectory("${INCLUDE_DIR}/imod/CMake" "${AUX_INCLUDE_DIR}/imod")
add_subdirectory("${INCLUDE_DIR}/icomp/CMake" "${AUX_INCLUDE_DIR}/icomp")

add_subdirectory("${INCLUDE_DIR}/idoc/CMake" "${AUX_INCLUDE_DIR}/idoc")
add_subdirectory("${INCLUDE_DIR}/iprm/CMake" "${AUX_INCLUDE_DIR}/iprm")
add_subdirectory("${INCLUDE_DIR}/ibase/CMake" "${AUX_INCLUDE_DIR}/ibase")
add_subdirectory("${INCLUDE_DIR}/iqt/CMake" "${AUX_INCLUDE_DIR}/iqt")
add_subdirectory("${INCLUDE_DIR}/iqt2d/CMake" "${AUX_INCLUDE_DIR}/iqt2d")
add_subdirectory("${INCLUDE_DIR}/iqtdoc/CMake" "${AUX_INCLUDE_DIR}/iqtdoc")
add_subdirectory("${INCLUDE_DIR}/iwidgets/CMake" "${AUX_INCLUDE_DIR}/iwidgets")
add_subdirectory("${INCLUDE_DIR}/iqtgui/CMake" "${AUX_INCLUDE_DIR}/iqtgui")
add_subdirectory("${INCLUDE_DIR}/ifilegui/CMake" "${AUX_INCLUDE_DIR}/ifilegui")
add_subdirectory("${INCLUDE_DIR}/iloggui/CMake" "${AUX_INCLUDE_DIR}/iloggui")
add_subdirectory("${INCLUDE_DIR}/iqtprm/CMake" "${AUX_INCLUDE_DIR}/iqtprm")
add_subdirectory("${INCLUDE_DIR}/ipackage/CMake" "${AUX_INCLUDE_DIR}/ipackage")

add_subdirectory("${INCLUDE_DIR}/itest/CMake" "${AUX_INCLUDE_DIR}/itest")

# Impl

add_subdirectory("${IMPL_DIR}/BasePck/CMake" "${AUX_INCLUDE_DIR}/BasePck")
add_subdirectory("${IMPL_DIR}/BitmapPck/CMake" "${AUX_INCLUDE_DIR}/BitmapPck")
add_subdirectory("${IMPL_DIR}/QtPck/CMake" "${AUX_INCLUDE_DIR}/QtPck")
add_subdirectory("${IMPL_DIR}/FilePck/CMake" "${AUX_INCLUDE_DIR}/FilePck")
add_subdirectory("${IMPL_DIR}/QtGuiPck/CMake" "${AUX_INCLUDE_DIR}/QtGuiPck")
add_subdirectory("${IMPL_DIR}/QtViewPck/CMake" "${AUX_INCLUDE_DIR}/QtViewPck")
add_subdirectory("${IMPL_DIR}/PackagePck/CMake" "${AUX_INCLUDE_DIR}/PackagePck")
add_subdirectory("${IMPL_DIR}/FileGuiPck/CMake" "${AUX_INCLUDE_DIR}/FileGuiPck")
add_subdirectory("${IMPL_DIR}/ArxcExe/CMake" "${AUX_INCLUDE_DIR}/ArxcExe")
add_subdirectory("${IMPL_DIR}/AcfExe/CMake" "${AUX_INCLUDE_DIR}/AcfExe")

add_subdirectory("${IMPL_DIR}/AcfLoc/CMake" "${AUX_INCLUDE_DIR}/AcfLoc")
