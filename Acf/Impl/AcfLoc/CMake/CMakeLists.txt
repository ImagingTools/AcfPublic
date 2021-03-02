set(ARXC_CONFIG "${CONFIG_DIR}/../AcfConfig.awc")
set(ARXC_FILES "${CMAKE_CURRENT_LIST_DIR}/../${PROJECT_NAME}.acc")
set(ARXC_OUTDIR "${AUX_INCLUDE_DIR}")

include(${CONFIG_DIR}/CustomBuild.cmake)
include(${CONFIG_DIR}/QtBaseConfig.cmake)
include(${CONFIG_DIR}/StaticConfig.cmake)
