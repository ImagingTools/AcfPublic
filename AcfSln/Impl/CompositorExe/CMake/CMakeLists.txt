set(ARXC_CONFIG "${CONFIGSLN_DIR}/AcfSlnConfig.awc")
set(ARXC_FILES "${CMAKE_CURRENT_LIST_DIR}/../${PROJECT_NAME}.acc")
set(ARXC_OUTDIR "${AUX_INCLUDE_DIR}")


include(${CONFIG_DIR}/CustomBuild.cmake)

#target_link_libraries(${PROJECT_NAME} "${ACFLIBDIR}/iqtgui.lib")
include(${CONFIG_DIR}/QtGuiBaseConfig.cmake)
include(${CONFIG_DIR}/ApplicationConfig.cmake)
include(${CONFIG_DIR}/AcfQt.cmake)
include(${CONFIG_DIR}/AcfStd.cmake)

message("ARXC_CONFIG")
message("${ARXC_CONFIG}")

find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS PrintSupport REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::PrintSupport)
