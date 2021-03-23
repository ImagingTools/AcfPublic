cmake_minimum_required(VERSION 3.1.0)

project(AcfAll)

set(QT_DEFAULT_MAJOR_VERSION 5)

#if(DEFINED ENV{ACFDIR})
#	set(ACFDIR $ENV{ACFDIR})
#else()
#	set(ACFDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf")
#endif()

#if(DEFINED ENV{ACFSLNDIR})
#	set(ACFSLNDIR $ENV{ACFSLNDIR})
#else()
#	set(ACFSLNDIR "${CMAKE_CURRENT_LIST_DIR}../../AcfSln")
#endif()

set(ACFDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf")
set(ACFSLNDIR "${CMAKE_CURRENT_LIST_DIR}../../AcfSln")


#	set(CONFIG_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf/Config/CMake")
set(CONFIGSLN_DIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Config")

include("${ACFDIR}/Config/CMake/Macro.cmake")

message("ACFDIR: " ${ACFDIR})
message("ACFSLNDIR: " ${ACFSLNDIR})

get_target_name(TARGETNAME)



#set(ACFBINDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf/Bin/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
#set(ACFLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf/Lib/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
#set(ACFSLNBINDIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Bin/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
#set(ACFSLNLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Lib/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
#set(ACFBINDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf/Bin/${TARGETNAME}")
set(ACFLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf/Lib/${TARGETNAME}")
#set(ACFSLNBINDIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Bin/${TARGETNAME}")
set(ACFSLNLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Lib/${TARGETNAME}")

#link_directories(${ACFDIR}/Lib/${TARGETNAME})

#link_directories(${ACFSLNDIR}/Lib/${TARGETNAME})

#list(APPEND PROJECTS "Acf")
#list(APPEND PROJECTS "AcfSln")
#list(APPEND PROJECTS "Iacf")

#foreach(PROJECT ${PROJECTS})
#		set(PROJECT_DIR "${CMAKE_CURRENT_LIST_DIR}/../../${PROJECT}")
#		set(SOURCES_DIR "${PROJECT_DIR}/Build/CMake/")
#		set(BINARY_DIR "${PROJECT_DIR}/Bin/${TARGETNAME}")
#        add_subdirectory("${SOURCES_DIR}" "${BINARY_DIR}")
#endforeach()

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../Acf/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../Acf/AuxInclude/${TARGETNAME}")
#add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/AuxInclude/${TARGETNAME}")
#add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../../IAcf/Build/CMake/" "${CMAKE_CURRENT_LIST_DIR}/../../IAcf/AuxInclude/${TARGETNAME}")

#add_dependencies(ialgo iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd)
#add_dependencies(ialgo iqtdoc iview iqt2d iqtprm iloggui ifilegui iqtgui iwidgets)


