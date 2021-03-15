#include(${ACFDIR}/Config/CMake/AcfQt.cmake)
#link_libraries("libimod.a" "libistd.a" "libipackage.a" "libibase.a" "libiser.a" "libilog.a" "libi2d.a" "libicomp.a" "libifile.a")
#link_libraries(${FILES_N})

project(Arxc LANGUAGES CXX)
#set(PROJECT_NAME Arxc)

#link_libraries(iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd)

include(${ACFDIR}/Config/CMake/QtBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/ApplicationConfig.cmake)
include(${ACFDIR}/Config/CMake/AcfStd.cmake)

#add_dependencies(${PROJECT_NAME} iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd)
#add_dependencies(${PROJECT_NAME} iqtdoc iview iqt2d iqtprm iloggui ifilegui iqtgui iwidgets)

message("ACFLIBDIR " "${ACFDIR}/Lib/${TARGETNAME}")
message("ACFSLNLIBDIR " "${ACFSLNDIR}/Lib/${TARGETNAME}")
message("PROJECT_NAME " "${PROJECT_NAME}")
#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFDIR}/Lib/${TARGETNAME})
#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFSLNDIR}/Lib/${TARGETNAME})

#target_link_libraries(${PROJECT_NAME} iser )
#target_link_libraries(${PROJECT_NAME} iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd)
