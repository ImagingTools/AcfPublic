project(XpcEditor LANGUAGES CXX)
#set(PROJECT_NAME XpcEditor)

set(ARXC_CONFIG "${ACFSLNDIR}/Config/AcfSlnConfig.awc")
set(ARXC_FILES "${PROJECT_SOURCE_DIR}/../${PROJECT_NAME}.acc")
set(ARXC_OUTDIR "${AUX_INCLUDE_DIR}")

set(CMAKE_WIN32_EXECUTABLE "on")


set(ACF_CONVERT_FILES "${PROJECT_SOURCE_DIR}/../VC/XpcEditor.rc.xtracf")
set(ACF_CONVERT_REGISTRY "${PROJECT_SOURCE_DIR}/../../../Partitura/AcfInfoCopyApp.acc")
set(ACF_CONVERT_CONFIG  "${PROJECT_SOURCE_DIR}/../../../Config/BaseOnly.awc")
set(RC_FILE "${AUX_INCLUDE_DIR}/${PROJECT_NAME}/XpcEditor.rc")


include(${ACFDIR}/Config/CMake/CustomBuild.cmake)
include(${ACFDIR}/Config/CMake/QtBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/ApplicationConfig.cmake)
include(${ACFDIR}/Config/CMake/AcfQt.cmake)
include(${ACFDIR}/Config/CMake/AcfStd.cmake)

#link_libraries("iqtgui icmpstr")
#target_link_libraries(${PROJECT_NAME} -liqt -lipackage -lidoc -lifile -liimg -licmm -li2d -li3d -liprm -lilog -libase -licomp -liattr -liser -limod -limath -listd)
#target_link_libraries(${PROJECT_NAME} -licmpstr -lAcfLoc -lAcfSlnLoc)
#target_link_libraries(${PROJECT_NAME} libicmpstr.a libAcfLoc.a libAcfSlnLoc.a)
#target_link_libraries(${PROJECT_NAME} -liqtdoc -liview -liqt2d -liqtprm -liloggui -lifilegui -liqtgui -liwidgets)
acf_link_libraries(${PROJECT_NAME} icmpstr AcfLoc AcfSlnLoc)
add_dependencies(${PROJECT_NAME} icmpstr AcfLoc AcfSlnLoc CompositorPck)

find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS PrintSupport REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::PrintSupport)
