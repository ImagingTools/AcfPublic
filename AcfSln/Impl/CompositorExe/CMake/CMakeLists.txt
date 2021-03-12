project(Compositor LANGUAGES CXX)

set(ARXC_CONFIG "${ACFSLNDIR}/Config/AcfSlnConfig.awc")
set(ARXC_FILES "${CMAKE_CURRENT_LIST_DIR}/../${PROJECT_NAME}.acc")
set(ARXC_OUTDIR "${AUX_INCLUDE_DIR}")

#set(PROJECT_BINARY_DIR ${AUX_INCLUDE_DIR}/${PROJECT_NAME})
#set(BINARY_DIR ${AUX_INCLUDE_DIR}/${PROJECT_NAME})
#set(PROJECT_BINARY_DIR ${AUX_INCLUDE_DIR}/${PROJECT_NAME})


#link_libraries(iqtgui icmpstr AcfSlnLoc AcfLoc)
#target_link_libraries(${PROJECT_NAME} "${ACFLIBDIR}/iqtgui.lib")
include(${ACFDIR}/Config/CMake/CustomBuild.cmake)
include(${ACFDIR}/Config/CMake/QtGuiBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/ApplicationConfig.cmake)
include(${ACFDIR}/Config/CMake/AcfQt.cmake)
include(${ACFDIR}/Config/CMake/AcfStd.cmake)

#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFLIBDIR})

#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFSLNLIBDIR})
#add_dependencies(${PROJECT_NAME} icmpstr)

#target_link_libraries(${PROJECT_NAME} iser istd icomp iqtgui libicmpstr.a AcfSlnLoc AcfLoc)
#target_link_libraries(${PROJECT_NAME} -licmpstr -lAcfSlnLoc -lAcfLoc)
#target_link_libraries(${PROJECT_NAME} icmpstr AcfSlnLoc AcfLoc)
acf_link_libraries(${PROJECT_NAME} icmpstr AcfLoc AcfSlnLoc)

#if(WIN32)
#	target_link_libraries(${PROJECT_NAME} iser istd icomp iqtgui libicmpstr.a libAcfSlnLoc.a libAcfLoc.a)
#else()
#	target_link_libraries(${PROJECT_NAME} iser istd icomp iqtgui libicmpstr.a libAcfSlnLoc.a libAcfLoc.a)
#endif()
find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS PrintSupport REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::PrintSupport)
