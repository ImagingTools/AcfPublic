#include(${CONFIG_DIR}/AcfQt.cmake)
#link_libraries("libimod.a" "libistd.a" "libipackage.a" "libibase.a" "libiser.a" "libilog.a" "libi2d.a" "libicomp.a" "libifile.a")
#link_libraries(${FILES_N})

#project(ArxcExe LANGUAGES CXX)
set(PROJECT_NAME Arxc)

#link_libraries(iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd)

include(${CONFIG_DIR}/QtBaseConfig.cmake)
include(${CONFIG_DIR}/ApplicationConfig.cmake)
include(${CONFIG_DIR}/AcfStd.cmake)



message("ACFLIBDIR " "${ACFLIBDIR}")
message("ACFSLNLIBDIR " "${ACFSLNLIBDIR}")
message("PROJECT_NAME " "${PROJECT_NAME}")
#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFLIBDIR})
#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFSLNLIBDIR})

#target_link_libraries(${PROJECT_NAME} iser )
#target_link_libraries(${PROJECT_NAME} iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd)
