cmake_minimum_required(VERSION 3.1.0)

project(AcfAll)

set(QT_DEFAULT_MAJOR_VERSION 5)

set(CONFIG_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf/Config/CMake")
set(CONFIGSLN_DIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Config")

include("${CONFIG_DIR}/Macro.cmake")

#list(APPEND PROJECTS "Acf" "AcfSln")
list(APPEND PROJECTS "Acf")
list(APPEND PROJECTS "AcfSln")
#"Iacf")

get_target_name(TARGETNAME)

set(ACFBINDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf/Bin/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
set(ACFLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../Acf/Lib/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
set(ACFSLNBINDIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Bin/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
set(ACFSLNLIBDIR "${CMAKE_CURRENT_LIST_DIR}/../../AcfSln/Lib/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")

foreach(PROJECT_NAME ${PROJECTS})
        set(PROJECT_DIR "${CMAKE_CURRENT_LIST_DIR}/../../${PROJECT_NAME}")
        set(SOURCES_DIR "${PROJECT_DIR}/Build/CMake/")
        set(BINARY_DIR "${PROJECT_DIR}/Bin/${TARGETNAME}")
        add_subdirectory("${SOURCES_DIR}" "${BINARY_DIR}")
endforeach()
