message(${CMAKE_CURRENT_LIST_DIR})
cmake_minimum_required(VERSION 3.1.0)

project(Acf)

set(QT_DEFAULT_MAJOR_VERSION 5)

include("${CONFIG_DIR}/Macro.cmake")

set(INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Include")
set(IMPL_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Impl")

message(${INCLUDE_DIR})

subdirlist(INCLUDE_DIRS ${INCLUDE_DIR})
subdirlist(IMPL_DIRS ${IMPL_DIR})

get_target_name(TARGETNAME)

set(LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Lib/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")

set(AUX_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../AuxInclude/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}/GeneratedFiles")

set(ACFBINDIR "${CMAKE_CURRENT_LIST_DIR}/../../Bin/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")

list(APPEND DEPENDSY_SUBDIRS_INCLUDE 
"istd"
"iser"
"ilog"
"i2d"
"i3d"
"iattr"
"iimg"
"imath"
"icmm"
"imod"
"icomp"
"idoc"
"iprm"
"ibase"
"iqt"
"ifile"
"iqt2d"
"iview"
"iqtdoc"
"iwidgets"
"iqtgui"
"ifilegui"
"iloggui"
"iqtprm"
"ipackage"
"itest"
)

list(APPEND DEPENDSY_SUBDIRS_IMPL 
    "BasePck"
    "BitmapPck"
    "QtPck"
    "FilePck"
    "QtGuiPck"
    "QtViewPck"
    "PackagePck"
    "FileGuiPck"
    "ArxcExe"
    "AcfExe"
    "AcfLoc"
)

list(APPEND LIB_LIST "")
list(APPEND REPLACE_LIST "Pck" "Exe" "Loc")

include_directories(${AUX_INCLUDE_DIR}/..)


FOREACH(SUBDIR ${DEPENDSY_SUBDIRS_INCLUDE})
	set(PROJECT_NAME ${SUBDIR})
        set(PROJECT_DIR "${INCLUDE_DIR}/${PROJECT_NAME}")
        set(SOURCES_DIR "${INCLUDE_DIR}/${PROJECT_NAME}/CMake")
        set(BINARY_DIR "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
#        set(LIBRARY_OUTPUT_PATH "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
#        set(EXECUTABLE_OUTPUT_PATH "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
#        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
	add_subdirectory(${SOURCES_DIR} ${BINARY_DIR})
        list(APPEND LIB_DIRS "${LIB_DIR}/${PROJECT_NAME}")
	list(APPEND LIB_LIST ${PROJECT_NAME})
ENDFOREACH()
#
FOREACH(SUBDIR ${DEPENDSY_SUBDIRS_IMPL})
	set(PROJECT_NAME ${SUBDIR})
        set(PROJECT_DIR "${IMPL_DIR}/${PROJECT_NAME}")
        set(SOURCES_DIR "${IMPL_DIR}/${PROJECT_NAME}/CMake")
        list(APPEND LIB_DIRS "${LIB_DIR}/${PROJECT_NAME}")
        if(NOT ${PROJECT_NAME}   MATCHES ".*Loc")
            STRING(REGEX REPLACE "([^ ]*)...$" "\\1" PROJECT_NAME ${PROJECT_NAME})
        endif()
        set(BINARY_DIR "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
        add_subdirectory(${SOURCES_DIR} ${BINARY_DIR})
ENDFOREACH()
