include(${CONFIG_DIR}/QtBaseConfig.cmake)
include(${CONFIG_DIR}/ApplicationConfig.cmake)
include(${CONFIG_DIR}/AcfStd.cmake)
include(${CONFIG_DIR}/AcfQt.cmake)

target_link_libraries(${PROJECT_NAME} iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd)
