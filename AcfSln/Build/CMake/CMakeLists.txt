cmake_minimum_required(VERSION 3.1.0)

project(AcfSln)

set(QT_DEFAULT_MAJOR_VERSION 5)

include(${CONFIG_DIR}/Macro.cmake)

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
"ialgo"
"iauth"
"ibarcode"
"icomm"
"ihotf"
"ihotfgui"
"imeas"
"iqtmeas"
"iqtex"
"iqtmm"
"icalib"
"icalibgui"
"icam"
"iqtcam"
"iqtauth"
"iinsp"
"iqtinsp"
"iipr"
"iqtipr"
"isig"
"iqtsig"
"ifileproc"
"iprod"
"iproc"
"iprocgui"
"iweb"
"iwiz"
"iwizgui"
"iedge"
"iedgegui"
"icmpstr"
"idocproc"
"iblob"
"iblobgui"
"iservice"
)

list(APPEND DEPENDSY_SUBDIRS_IMPL
"AcfSlnLoc"
"AuthorizationPck"
"BlobPck"
"BarcodePck"
"ProcessingPck"
"FileProcessingPck"
"CameraPck"
"CalibrationPck"
"CommunicationPck"
"EdgePck"
"HotfolderPck"
"InspectionPck"
"IprPck"
"MeasPck"
"SignalPck"
"WebPck"
"WizardPck"
"QtAuthorizationPck"
"QtCameraPck"
"CalibrationGuiPck"
"QtExPck"
"QtInspectionPck"
"QtIprPck"
"QtMeasPck"
"QtMmPck"
"QtSignalPck"
"WizardGuiPck"
"HotfolderGuiPck"
"ProcessingGuiPck"
"CompositorPck"
"DocumentProcessingPck"
"ProductionPck"
"XpcEditorExe"
"CompositorExe"
)

FOREACH(SUBDIR ${DEPENDSY_SUBDIRS_INCLUDE})
        set(PROJECT_NAME ${SUBDIR})
        set(PROJECT_DIR "${INCLUDE_DIR}/${PROJECT_NAME}")
        set(SOURCES_DIR "${INCLUDE_DIR}/${PROJECT_NAME}/CMake")
        set(BINARY_DIR "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
        add_subdirectory(${SOURCES_DIR} ${BINARY_DIR})
        list(APPEND LIB_DIRS "${LIB_DIR}/${PROJECT_NAME}")
#        set(LIB_LIST ${LIB_LIST} ${PROJECT_NAME}.lib PARENT_SCOPE)
ENDFOREACH()

FOREACH(SUBDIR ${DEPENDSY_SUBDIRS_IMPL})
        set(PROJECT_NAME ${SUBDIR})
        set(PROJECT_DIR "${IMPL_DIR}/${PROJECT_NAME}")
        set(SOURCES_DIR "${IMPL_DIR}/${PROJECT_NAME}/CMake")
        list(APPEND LIB_DIRS "${LIB_DIR}/${PROJECT_NAME}")
        if(${PROJECT_NAME}   MATCHES ".*Exe")
            STRING(REGEX REPLACE "([^ ]*)...$" "\\1" PROJECT_NAME ${PROJECT_NAME})
        endif()

        #        if(NOT ${PROJECT_NAME}  MATCHES ".*Pck" )
#            STRING(REGEX REPLACE "([^ ]*)...$" "\\1" PROJECT_NAME ${PROJECT_NAME})
#        endif()

        set(BINARY_DIR "${AUX_INCLUDE_DIR}/${PROJECT_NAME}")
        add_subdirectory(${SOURCES_DIR} ${BINARY_DIR})
ENDFOREACH()
