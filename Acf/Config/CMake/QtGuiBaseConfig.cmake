# Standard settings for a Qt based UI project
#message("Include QtGuiBaseConfig.cmake")
include (${ACFDIR}/Config/CMake/QtBaseConfig.cmake)

if(${QT_DEFAULT_MAJOR_VERSION} STREQUAL 5)
	find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS Widgets REQUIRED)
endif()

function(acf_wrap_ui outfiles)
	if(QT_DEFAULT_MAJOR_VERSION EQUAL 5)
		qt5_wrap_ui("${outfiles}" ${ARGN})
	elseif(QT_DEFAULT_MAJOR_VERSION EQUAL 6)
		qt6_wrap_ui("${outfiles}" ${ARGN})
	endif()
	set("${outfiles}" "${${outfiles}}" PARENT_SCOPE)
endfunction()
