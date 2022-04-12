#General base configuration should be included from all ACF-based projects

message("PROJECT_NAME " ${PROJECT_NAME})
message("CMAKE_CURRENT_LIST_DIR " ${CMAKE_CURRENT_LIST_DIR})
message("PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
message("BINARY_DIR " ${BINARY_DIR})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(AUXINCLUDEDIR "AuxInclude/${TARGETNAME}/GeneratedFiles")
set(AUXINCLUDEPATH "${PROJECT_SOURCE_DIR}/../../../${AUXINCLUDEDIR}")
#set(ACF_TRANSLATIONS_OUTDIR "${AUXINCLUDEPATH}/${TARGETNAME}")

find_package("Qt${QT_VERSION_MAJOR}" COMPONENTS Core Widgets Core Gui Xml Network Svg Concurrent REQUIRED)

include_directories("${PROJECT_SOURCE_DIR}/../../")

include_directories("${INCLUDE_DIR}")
include_directories("${IMPL_DIR}")


function(acf_create_moc outfiles)
	if(QT_VERSION_MAJOR EQUAL 5)
		qt5_wrap_cpp("${outfiles}" ${ARGN} )
	elseif(QT_VERSION_MAJOR EQUAL 6)
		qt6_wrap_cpp("${outfiles}" ${ARGN} )
	endif()
	set("${outfiles}" "${${outfiles}}" PARENT_SCOPE)
endfunction()

function(acf_wrap_resources outfiles)
	if(QT_VERSION_MAJOR EQUAL 5)
		qt5_add_resources("${outfiles}" ${ARGN})
	elseif(QT_VERSION_MAJOR EQUAL 6)
		qt6_add_resources("${outfiles}" ${ARGN})
	endif()
	set("${outfiles}" "${${outfiles}}" PARENT_SCOPE)
endfunction()

function(acf_wrap_ui outfiles)
	if(QT_VERSION_MAJOR EQUAL 5)
		qt5_wrap_ui("${outfiles}" ${ARGN})
	elseif(QT_VERSION_MAJOR EQUAL 6)
		qt6_wrap_ui("${outfiles}" ${ARGN})
	endif()
	set("${outfiles}" "${${outfiles}}" PARENT_SCOPE)
endfunction()

if(${MSVC})
	link_libraries("Mpr.lib")
endif()

function(acf_use_qt_modules)
	target_link_libraries(${PROJECT_NAME}  Qt${QT_VERSION_MAJOR}::Core)
	target_link_libraries(${PROJECT_NAME}  Qt${QT_VERSION_MAJOR}::Widgets)
	target_link_libraries(${PROJECT_NAME}  Qt${QT_VERSION_MAJOR}::Gui)
	target_link_libraries(${PROJECT_NAME}  Qt${QT_VERSION_MAJOR}::Xml)
	target_link_libraries(${PROJECT_NAME}  Qt${QT_VERSION_MAJOR}::Network)
	target_link_libraries(${PROJECT_NAME}  Qt${QT_VERSION_MAJOR}::Svg)
	target_link_libraries(${PROJECT_NAME}  Qt${QT_VERSION_MAJOR}::Concurrent)
endfunction()
