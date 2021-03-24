include(${CMAKE_CURRENT_LIST_DIR}/GeneralConfig.cmake)

#if(${QT_DEFAULT_MAJOR_VERSION} STREQUAL 5)
##	message("COMPONENTS Widgets")
#        find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS Widgets REQUIRED)
#endif()
message("PROJECT_SOURCE_DIR "  ${PROJECT_SOURCE_DIR})

#file(GLOB UI_FILES "${PROJECT_SOURCE_DIR}/../*.ui")
file(GLOB HEADER_FILES "${PROJECT_SOURCE_DIR}/../*.h")
file(GLOB SOURCES_FILES "${PROJECT_SOURCE_DIR}/../*.cpp")
file(GLOB QRC_FILES "${PROJECT_SOURCE_DIR}/../*.qrc")

file(GLOB PROJECT_SRC
		${MOC_SOURCES}
        ${HEADER_FILES}
        ${SOURCES_FILES}
#        ${RESOURCES_FILES}
#        ${HEADER_FILES_AUX}
#        ${SOURCES_FILES_AUX}
#		${MOC_SOURCES}
		${QRC_FILES}
)

#message(MOC_SOURCES "${MOC_SOURCES}")
#message("SOURCES_FILES_AUX")
#message("${SOURCES_FILES_AUX}")
#set(TARGET_EXT ".lib")

add_library(${PROJECT_NAME} STATIC ${PROJECT_SRC})


#message("MOC_SOURCES " "${MOC_SOURCES}")

target_sources(${PROJECT_NAME} PUBLIC ${MOC_SOURCES})
target_sources(${PROJECT_NAME} PUBLIC ${UI_FILES})
target_sources(${PROJECT_NAME} PUBLIC ${RESOURCES_FILES})
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES_FILE_AUX})

#set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ${TARGET_EXT})
#set_target_properties(${PROJECT_NAME} PROPERTIES AUTOGEN_BUILD_DIR "${ACF_TRANSLATIONS_OUTDIR}")
set(outlibdir "${AUX_INCLUDE_DIR}/../../../Lib/${TARGETNAME}")

set_property(
	TARGET ${PROJECT_NAME}
	PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${outlibdir})

set_property(
	TARGET ${PROJECT_NAME}
	PROPERTY LIBRARY_OUTPUT_DIRECTORY ${outlibdir})
#set(LIBRARY_OUTPUT_PATH "${outbindir}")

#qt5_use_modules(${PROJECT_NAME} Core Widgets Gui Xml Network XmlPatterns Svg Concurrent)
qt5_use_modules(${PROJECT_NAME} Core)

#set(LIBRARY_OUTPUT_PATH "${ACFDIRBUILD}")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${ACFDIRBUILD}")

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ACFDIRBUILD}")

