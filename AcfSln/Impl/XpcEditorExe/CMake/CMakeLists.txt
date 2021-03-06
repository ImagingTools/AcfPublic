set(ARXC_CONFIG "${CONFIGSLN_DIR}/AcfSlnConfig.awc")
set(ARXC_FILES "${CMAKE_CURRENT_LIST_DIR}/../${PROJECT_NAME}.acc")
set(ARXC_OUTDIR "${AUX_INCLUDE_DIR}")


include(${CONFIG_DIR}/CustomBuild.cmake)
include(${CONFIG_DIR}/QtBaseConfig.cmake)
include(${CONFIG_DIR}/ApplicationConfig.cmake)
include(${CONFIG_DIR}/AcfQt.cmake)
include(${CONFIG_DIR}/AcfStd.cmake)

#link_libraries("iqtgui icmpstr")
target_link_libraries(${PROJECT_NAME} -licmpstr -lAcfLoc -lAcfSlnLoc)

find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS PrintSupport REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::PrintSupport)
