# Standard settings for a Qt based UI project
#message("Include QtGuiBaseConfig.cmake")
include (${CONFIG_DIR}/QtBaseConfig.cmake)

if(${QT_DEFAULT_MAJOR_VERSION} STREQUAL 5)
#	message("COMPONENTS Widgets")
        find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS Widgets REQUIRED)
endif()

#function(qt_wrap_ui_acf outfiles)
#    if(QT_DEFAULT_MAJOR_VERSION EQUAL 5)
#        qt5_wrap_ui("${outfiles}" ${ARGN})
#    elseif(QT_DEFAULT_MAJOR_VERSION EQUAL 6)
#        qt6_wrap_ui("${outfiles}" ${ARGN})
#    endif()
#    set("${outfiles}" "${${outfiles}}" PARENT_SCOPE)
#endfunction()

file(GLOB UI_FILES_LOCAL "${PROJECT_DIR}/*.ui")
#qt_wrap_ui_acf(SOURCES ${UI_FILES})

#message("APPEND UI_FILES")

#foreach(it ${UI_FILES_LOCAL})
#    get_filename_component(outfilename ${it} NAME_WE)
#    get_filename_component(infile ${it} ABSOLUTE)
#    set(outfile ${CMAKE_CURRENT_BINARY_DIR}/ui_${outfilename}.h)
#    execute_process(COMMAND ${Qt5_DIR}/../../../bin/uic -o ${outfile} ${infile} )
#    list(APPEND UI_FILES ${outfile})
##    set(ARGS "${Qt5_DIR}/../../../bin/uic -o ${outfile} ${infile} ")
##    message("${ARGS}")
#endforeach()

set(UI_FILES_CHECK "0")

file(GLOB UI_FILES_LOCAL "${PROJECT_DIR}/*.ui")
foreach(UI_FILE ${UI_FILES_LOCAL})
    set(UI_FILES_CHECK "1")
    continue()
endforeach()

if(${UI_FILES_CHECK} STREQUAL "1")
	if(QT_DEFAULT_MAJOR_VERSION EQUAL 5)
		message(qt5_wrap_ui)
		qt5_wrap_ui(UI_FILES ${UI_FILES_LOCAL})
	elseif(QT_DEFAULT_MAJOR_VERSION EQUAL 6)
		qt6_wrap_ui(UI_FILES ${UI_FILES_LOCAL})
	endif()
endif()


