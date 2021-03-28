# Standard settings for a Qt based project
#message("Include QtBaseConfig.cmake")
#include(${CMAKE_CURRENT_LIST_DIR}/CompileDir.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/GeneralConfig.cmake)

if(${QT_DEFAULT_MAJOR_VERSION} STREQUAL 5)
#	message("COMPONENTS Core Gui Xml Network XmlPatterns Widgets Svg Concurrent")
        find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS Core Gui Xml Network XmlPatterns Svg Concurrent REQUIRED)
endif()

function(acf_wrap_resources outfiles)
	if(QT_DEFAULT_MAJOR_VERSION EQUAL 5)
		qt5_add_resources("${outfiles}" ${ARGN})
	elseif(QT_DEFAULT_MAJOR_VERSION EQUAL 6)
		qt6_add_resources("${outfiles}" ${ARGN})
	endif()
	set("${outfiles}" "${${outfiles}}" PARENT_SCOPE)
#	if(NOT "${outfiles}" STREQUAL "")
#    target_sources(${PROJECT_NAME} PUBLIC ${outfiles1})
#    endif()
endfunction()
#function(acf_wrap_resources outfiles)
##	set(outfiles)
#    if(QT_DEFAULT_MAJOR_VERSION EQUAL 5)
#		qt5_add_resources(outfiles ${ARGN})
#	elseif(QT_DEFAULT_MAJOR_VERSION EQUAL 6)
#		qt6_add_resources(outfiles ${ARGN})
#	endif()

#	set("${outfiles}" "${${outfiles}}" PARENT_SCOPE)
##    if(NOT "${outfiles}" STREQUAL "")
###		target_sources(${PROJECT_NAME} PUBLIC ${outfiles})
##    endif()
#endfunction()

#file(GLOB QRC_FILES "${PROJECT_SOURCE_DIR}/../*.qrc")
#qt_generate_moc(${SOURCES_FILES} TARGET ${PROJECT_NAME})
#acf_wrap_resources(RESOURCES_FILES ${QRC_FILES})


#foreach(it ${QRC_FILES})
#    get_filename_component(outfilename ${it} NAME_WE)
#    get_filename_component(infile ${it} ABSOLUTE)
#    set(outfile ${CMAKE_CURRENT_BINARY_DIR}/qrc_${outfilename}.cpp)
#    execute_process(COMMAND ${Qt5_DIR}/../../../bin/rcc --name ${outfilename} --output ${outfile} ${infile} )
## COMMAND ${Qt5Core_RCC_EXECUTABLE}
#    #    ARGS ${rcc_options} --name ${outfilename} --output ${outfile} ${infile}
#    list(APPEND RESOURCES_FILES ${outfile})
#    set(ARGS "${Qt5_DIR}/../../../bin/rcc --name ${outfilename} --output ${outfile} ${infile} ")
##    message("APPEND RESOURCES_FILES")
##    message("${ARGS}")
#endforeach()


#file(GLOB RESOURCES_FILES "${PROJECT_SOURCE_DIR}/../*.qrc")

#set(RESOURCES_FILES_CHECK "0")
#foreach(RESOURCES_FILE ${RESOURCES_FILES})
#    set(RESOURCES_FILES_CHECK "1")
#    continue()
#endforeach()

#if(${RESOURCES_FILES_CHECK} STREQUAL "1")
#    if(QT_DEFAULT_MAJOR_VERSION EQUAL 5)
#        qt5_add_binary_resources(resources${PROJECT_NAME} ${RESOURCES_FILES} OPTIONS -no-compress)
#    elseif(QT_DEFAULT_MAJOR_VERSION EQUAL 6)
#        qt6_add_binary_resources(resources${PROJECT_NAME} ${RESOURCES_FILES} OPTIONS -no-compress)
#    endif()
#endif()

