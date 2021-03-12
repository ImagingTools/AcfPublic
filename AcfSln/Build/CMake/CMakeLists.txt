cmake_minimum_required(VERSION 3.1.0)

project(AcfSln)

set(QT_DEFAULT_MAJOR_VERSION 5)

include(${ACFDIR}/Config/CMake/Macro.cmake)

set(MAIN_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Include/")

subdirlist(SUBDIRS ${MAIN_DIR})

get_target_name(TARGETNAME)

set(ACF_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../Acf/Include")
set(ACF_IMPL_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../Acf/Impl")

message(${ACF_INCLUDE_DIR})

include_directories("${ACF_INCLUDE_DIR}")
include_directories("${ACF_IMPL_DIR}")

set(INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Include")
set(IMPL_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Impl")

subdirlist(INCLUDE_DIRS ${INCLUDE_DIR})
subdirlist(IMPL_DIRS ${IMPL_DIR})

set(LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Lib/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")

set(AUX_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../AuxInclude/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}/GeneratedFiles")

include_directories("${CMAKE_CURRENT_LIST_DIR}/../../AuxInclude/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
include_directories("${CMAKE_CURRENT_LIST_DIR}/../../../Acf/AuxInclude/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")

message("${AUX_INCLUDE_DIR}")

list(APPEND DEPENDSY_SUBDIRS_INCLUDE
#"ialgo"
#"iauth"
#"ibarcode"
#"icomm"
#"ihotf"
#"ihotfgui"
#"imeas"
#"iqtmeas"
#"iqtex"
#"iqtmm"
#"icalib"
#"icalibgui"
#"icam"
#"iqtcam"
#"iqtauth"
#"iinsp"
#"iqtinsp"
#"iipr"
#"iqtipr"
#"isig"
#"iqtsig"
#"ifileproc"
#"iprod"
#"iproc"
#"iprocgui"
#"iweb"
#"iwiz"
#"iwizgui"
#"iedge"
#"iedgegui"
#"icmpstr"
#"idocproc"
#"iblob"
#"iblobgui"
#"iservice"
)

list(APPEND DEPENDSY_SUBDIRS_IMPL
#"AcfSlnLoc"
#"AuthorizationPck"
#"BlobPck"
#"BarcodePck"
#"ProcessingPck"
#"FileProcessingPck"
#"CameraPck"
#"CalibrationPck"
#"CommunicationPck"
#"EdgePck"
#"HotfolderPck"
#"InspectionPck"
#"IprPck"
#"MeasPck"
#"SignalPck"
#"WebPck"
#"WizardPck"
#"QtAuthorizationPck"
#"QtCameraPck"
#"CalibrationGuiPck"
#"QtExPck"
#"QtInspectionPck"
#"QtIprPck"
#"QtMeasPck"
#"QtMmPck"
#"QtSignalPck"
#"WizardGuiPck"
#"HotfolderGuiPck"
#"ProcessingGuiPck"
#"CompositorPck"
#"DocumentProcessingPck"
#"ProductionPck"
#"XpcEditorExe"
#"CompositorExe"
)

#FOREACH(SUBDIR ${DEPENDSY_SUBDIRS_INCLUDE})
##        set(PROJECT_NAME ${SUBDIR})
#		set(PROJECT_DIR "${INCLUDE_DIR}/${SUBDIR}")
#		set(SOURCES_DIR "${INCLUDE_DIR}/${SUBDIR}/CMake")
#		set(BINARY_DIR "${AUX_INCLUDE_DIR}/${SUBDIR}")
#        add_subdirectory(${SOURCES_DIR} ${BINARY_DIR})
#		add_dependencies(${SUBDIR} Arxc)

##        list(APPEND LIB_DIRS "${LIB_DIR}/${PROJECT_NAME}")
##        set(LIB_LIST ${LIB_LIST} ${PROJECT_NAME}.lib PARENT_SCOPE)
#ENDFOREACH()

#FOREACH(SUBDIR ${DEPENDSY_SUBDIRS_IMPL})
##		set(PROJECT_NAME ${SUBDIR})
#		set(PROJECT_DIR "${IMPL_DIR}/${SUBDIR}")
#		set(SOURCES_DIR "${IMPL_DIR}/${SUBDIR}/CMake")
##		list(APPEND LIB_DIRS "${LIB_DIR}/${PROJECT_NAME}")
#		if(${SUBDIR}   MATCHES ".*Exe")
#			STRING(REGEX REPLACE "([^ ]*)...$" "\\1" SUBDIR ${SUBDIR})
#		endif()

#        #        if(NOT ${PROJECT_NAME}  MATCHES ".*Pck" )
##            STRING(REGEX REPLACE "([^ ]*)...$" "\\1" PROJECT_NAME ${PROJECT_NAME})
##        endif()

#		set(BINARY_DIR "${AUX_INCLUDE_DIR}/${SUBDIR}")
#		add_subdirectory(${SOURCES_DIR} ${BINARY_DIR})
##		add_subdirectory(${SOURCES_DIR})
##		add_dependencies(${PROJECT_NAME} Arxc)

#ENDFOREACH()
# Include

add_subdirectory("${INCLUDE_DIR}/ialgo/CMake" "${AUX_INCLUDE_DIR}/ialgo")
add_subdirectory("${INCLUDE_DIR}/iauth/CMake" "${AUX_INCLUDE_DIR}/iauth")
add_subdirectory("${INCLUDE_DIR}/ibarcode/CMake" "${AUX_INCLUDE_DIR}/ibarcode")

add_subdirectory("${INCLUDE_DIR}/icomm/CMake" "${AUX_INCLUDE_DIR}/icomm")
add_subdirectory("${INCLUDE_DIR}/ihotf/CMake" "${AUX_INCLUDE_DIR}/ihotf")
add_subdirectory("${INCLUDE_DIR}/ihotfgui/CMake" "${AUX_INCLUDE_DIR}/ihotfgui")
add_subdirectory("${INCLUDE_DIR}/imeas/CMake" "${AUX_INCLUDE_DIR}/imeas")
add_subdirectory("${INCLUDE_DIR}/iqtmeas/CMake" "${AUX_INCLUDE_DIR}/iqtmeas")
add_subdirectory("${INCLUDE_DIR}/iqtex/CMake" "${AUX_INCLUDE_DIR}/iqtex")
add_subdirectory("${INCLUDE_DIR}/iqtmm/CMake" "${AUX_INCLUDE_DIR}/iqtmm")
add_subdirectory("${INCLUDE_DIR}/icalib/CMake" "${AUX_INCLUDE_DIR}/icalib")

add_subdirectory("${INCLUDE_DIR}/icalibgui/CMake" "${AUX_INCLUDE_DIR}/icalibgui")
add_subdirectory("${INCLUDE_DIR}/icam/CMake" "${AUX_INCLUDE_DIR}/icam")
add_subdirectory("${INCLUDE_DIR}/iqtcam/CMake" "${AUX_INCLUDE_DIR}/iqtcam")
add_subdirectory("${INCLUDE_DIR}/iqtauth/CMake" "${AUX_INCLUDE_DIR}/iqtauth")
add_subdirectory("${INCLUDE_DIR}/iinsp/CMake" "${AUX_INCLUDE_DIR}/iinsp")
add_subdirectory("${INCLUDE_DIR}/iipr/CMake" "${AUX_INCLUDE_DIR}/iipr")
add_subdirectory("${INCLUDE_DIR}/iqtipr/CMake" "${AUX_INCLUDE_DIR}/iqtipr")
add_subdirectory("${INCLUDE_DIR}/isig/CMake" "${AUX_INCLUDE_DIR}/isig")
add_subdirectory("${INCLUDE_DIR}/iqtsig/CMake" "${AUX_INCLUDE_DIR}/iqtsig")
add_subdirectory("${INCLUDE_DIR}/ifileproc/CMake" "${AUX_INCLUDE_DIR}/ifileproc")
add_subdirectory("${INCLUDE_DIR}/iprod/CMake" "${AUX_INCLUDE_DIR}/iprod")
add_subdirectory("${INCLUDE_DIR}/iproc/CMake" "${AUX_INCLUDE_DIR}/iproc")


add_subdirectory("${INCLUDE_DIR}/iprocgui/CMake" "${AUX_INCLUDE_DIR}/iprocgui")
add_subdirectory("${INCLUDE_DIR}/iweb/CMake" "${AUX_INCLUDE_DIR}/iweb")
add_subdirectory("${INCLUDE_DIR}/iwiz/CMake" "${AUX_INCLUDE_DIR}/iwiz")
add_subdirectory("${INCLUDE_DIR}/iwizgui/CMake" "${AUX_INCLUDE_DIR}/iwizgui")
add_subdirectory("${INCLUDE_DIR}/iedge/CMake" "${AUX_INCLUDE_DIR}/iedge")

add_subdirectory("${INCLUDE_DIR}/iedgegui/CMake" "${AUX_INCLUDE_DIR}/iedgegui")
add_subdirectory("${INCLUDE_DIR}/icmpstr/CMake" "${AUX_INCLUDE_DIR}/icmpstr")
add_subdirectory("${INCLUDE_DIR}/idocproc/CMake" "${AUX_INCLUDE_DIR}/idocproc")
add_subdirectory("${INCLUDE_DIR}/iblob/CMake" "${AUX_INCLUDE_DIR}/iblob")
add_subdirectory("${INCLUDE_DIR}/iblobgui/CMake" "${AUX_INCLUDE_DIR}/iblobgui")
add_subdirectory("${INCLUDE_DIR}/iservice/CMake" "${AUX_INCLUDE_DIR}/iservice")


# Impl

add_subdirectory("${IMPL_DIR}/AcfSlnLoc/CMake" "${AUX_INCLUDE_DIR}/AcfSlnLoc")
add_subdirectory("${IMPL_DIR}/AuthorizationPck/CMake" "${AUX_INCLUDE_DIR}/AuthorizationPck")
add_subdirectory("${IMPL_DIR}/BlobPck/CMake" "${AUX_INCLUDE_DIR}/BlobPck")
add_subdirectory("${IMPL_DIR}/BarcodePck/CMake" "${AUX_INCLUDE_DIR}/BarcodePck")
add_subdirectory("${IMPL_DIR}/ProcessingPck/CMake" "${AUX_INCLUDE_DIR}/ProcessingPck")
add_subdirectory("${IMPL_DIR}/FileProcessingPck/CMake" "${AUX_INCLUDE_DIR}/FileProcessingPck")
add_subdirectory("${IMPL_DIR}/CameraPck/CMake" "${AUX_INCLUDE_DIR}/CameraPck")
add_subdirectory("${IMPL_DIR}/CalibrationPck/CMake" "${AUX_INCLUDE_DIR}/CalibrationPck")
add_subdirectory("${IMPL_DIR}/CommunicationPck/CMake" "${AUX_INCLUDE_DIR}/CommunicationPck")
add_subdirectory("${IMPL_DIR}/EdgePck/CMake" "${AUX_INCLUDE_DIR}/EdgePck")
add_subdirectory("${IMPL_DIR}/HotfolderPck/CMake" "${AUX_INCLUDE_DIR}/HotfolderPck")
add_subdirectory("${IMPL_DIR}/InspectionPck/CMake" "${AUX_INCLUDE_DIR}/InspectionPck")
add_subdirectory("${IMPL_DIR}/IprPck/CMake" "${AUX_INCLUDE_DIR}/IprPck")
add_subdirectory("${IMPL_DIR}/MeasPck/CMake" "${AUX_INCLUDE_DIR}/MeasPck")
add_subdirectory("${IMPL_DIR}/SignalPck/CMake" "${AUX_INCLUDE_DIR}/SignalPck")
add_subdirectory("${IMPL_DIR}/WebPck/CMake" "${AUX_INCLUDE_DIR}/WebPck")
add_subdirectory("${IMPL_DIR}/WizardPck/CMake" "${AUX_INCLUDE_DIR}/WizardPck")
add_subdirectory("${IMPL_DIR}/QtAuthorizationPck/CMake" "${AUX_INCLUDE_DIR}/QtAuthorizationPck")
add_subdirectory("${IMPL_DIR}/QtCameraPck/CMake" "${AUX_INCLUDE_DIR}/QtCameraPck")
add_subdirectory("${IMPL_DIR}/CalibrationGuiPck/CMake" "${AUX_INCLUDE_DIR}/CalibrationGuiPck")
add_subdirectory("${IMPL_DIR}/QtExPck/CMake" "${AUX_INCLUDE_DIR}/QtExPck")
add_subdirectory("${IMPL_DIR}/QtInspectionPck/CMake" "${AUX_INCLUDE_DIR}/QtInspectionPck")
add_subdirectory("${IMPL_DIR}/QtIprPck/CMake" "${AUX_INCLUDE_DIR}/QtIprPck")
add_subdirectory("${IMPL_DIR}/QtMeasPck/CMake" "${AUX_INCLUDE_DIR}/QtMeasPck")
add_subdirectory("${IMPL_DIR}/QtMmPck/CMake" "${AUX_INCLUDE_DIR}/QtMmPck")
add_subdirectory("${IMPL_DIR}/QtSignalPck/CMake" "${AUX_INCLUDE_DIR}/QtSignalPck")
add_subdirectory("${IMPL_DIR}/WizardGuiPck/CMake" "${AUX_INCLUDE_DIR}/WizardGuiPck")
add_subdirectory("${IMPL_DIR}/HotfolderGuiPck/CMake" "${AUX_INCLUDE_DIR}/HotfolderGuiPck")
add_subdirectory("${IMPL_DIR}/ProcessingGuiPck/CMake" "${AUX_INCLUDE_DIR}/ProcessingGuiPck")
add_subdirectory("${IMPL_DIR}/CompositorPck/CMake" "${AUX_INCLUDE_DIR}/CompositorPck")
add_subdirectory("${IMPL_DIR}/DocumentProcessingPck/CMake" "${AUX_INCLUDE_DIR}/DocumentProcessingPck")
add_subdirectory("${IMPL_DIR}/ProductionPck/CMake" "${AUX_INCLUDE_DIR}/ProductionPck")

add_subdirectory("${IMPL_DIR}/XpcEditorExe/CMake" "${AUX_INCLUDE_DIR}/XpcEditor")
add_subdirectory("${IMPL_DIR}/CompositorExe/CMake" "${AUX_INCLUDE_DIR}/Compositor")

