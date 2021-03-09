set(ARXC_CONFIG "${CONFIGSLN_DIR}/AcfSlnConfig.awc")
set(ARXC_FILES "${CMAKE_CURRENT_LIST_DIR}/../${PROJECT_NAME}.acc")
set(ARXC_OUTDIR "${AUX_INCLUDE_DIR}")


set(PROJECT_NAME XpcEditor)

include(${CONFIG_DIR}/CustomBuild.cmake)
include(${CONFIG_DIR}/QtBaseConfig.cmake)
include(${CONFIG_DIR}/ApplicationConfig.cmake)
include(${CONFIG_DIR}/AcfQt.cmake)
include(${CONFIG_DIR}/AcfStd.cmake)

#link_libraries("iqtgui icmpstr")
#target_link_libraries(${PROJECT_NAME} -liqt -lipackage -lidoc -lifile -liimg -licmm -li2d -li3d -liprm -lilog -libase -licomp -liattr -liser -limod -limath -listd)
#target_link_libraries(${PROJECT_NAME} -licmpstr -lAcfLoc -lAcfSlnLoc)
#target_link_libraries(${PROJECT_NAME} libicmpstr.a libAcfLoc.a libAcfSlnLoc.a)
#target_link_libraries(${PROJECT_NAME} -liqtdoc -liview -liqt2d -liqtprm -liloggui -lifilegui -liqtgui -liwidgets)
acf_link_libraries(${PROJECT_NAME} icmpstr AcfLoc AcfSlnLoc)

find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS PrintSupport REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::PrintSupport)
