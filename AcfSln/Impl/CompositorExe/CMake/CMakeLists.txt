set(ARXC_CONFIG "${CONFIGSLN_DIR}/AcfSlnConfig.awc")
set(ARXC_FILES "${CMAKE_CURRENT_LIST_DIR}/../${PROJECT_NAME}.acc")
set(ARXC_OUTDIR "${AUX_INCLUDE_DIR}")



#link_libraries(iqtgui icmpstr AcfSlnLoc AcfLoc)
#target_link_libraries(${PROJECT_NAME} "${ACFLIBDIR}/iqtgui.lib")
include(${CONFIG_DIR}/CustomBuild.cmake)
include(${CONFIG_DIR}/QtGuiBaseConfig.cmake)
include(${CONFIG_DIR}/ApplicationConfig.cmake)
include(${CONFIG_DIR}/AcfQt.cmake)
include(${CONFIG_DIR}/AcfStd.cmake)

#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFLIBDIR})

#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFSLNLIBDIR})
add_dependencies(${PROJECT_NAME} icmpstr)

#target_link_libraries(${PROJECT_NAME} iser istd icomp iqtgui libicmpstr.a AcfSlnLoc AcfLoc)
target_link_libraries(${PROJECT_NAME} -licmpstr -lAcfSlnLoc -lAcfLoc)

#if(WIN32)
#	target_link_libraries(${PROJECT_NAME} iser istd icomp iqtgui libicmpstr.a libAcfSlnLoc.a libAcfLoc.a)
#else()
#	target_link_libraries(${PROJECT_NAME} iser istd icomp iqtgui libicmpstr.a libAcfSlnLoc.a libAcfLoc.a)
#endif()
find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS PrintSupport REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::PrintSupport)
