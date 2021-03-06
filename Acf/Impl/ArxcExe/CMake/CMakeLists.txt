#include(${CONFIG_DIR}/AcfQt.cmake)
#link_libraries("libimod.a" "libistd.a" "libipackage.a" "libibase.a" "libiser.a" "libilog.a" "libi2d.a" "libicomp.a" "libifile.a")
#link_libraries(${FILES_N})
include(${CONFIG_DIR}/QtBaseConfig.cmake)
include(${CONFIG_DIR}/ApplicationConfig.cmake)
include(${CONFIG_DIR}/AcfStd.cmake)



#target_link_libraries(${PROJECT_NAME} iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd)
