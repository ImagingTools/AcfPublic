include(${CMAKE_CURRENT_LIST_DIR}/GeneralConfig.cmake)

message("PROJECT_SOURCE_DIR "  ${PROJECT_SOURCE_DIR})

file(GLOB UI_FILES "${PROJECT_SOURCE_DIR}/../*.ui")
file(GLOB HEADER_FILES "${PROJECT_SOURCE_DIR}/../*.h")
file(GLOB SOURCES_FILES "${PROJECT_SOURCE_DIR}/../*.cpp")
file(GLOB QRC_FILES "${PROJECT_SOURCE_DIR}/../*.qrc")

file(GLOB PROJECT_SRC
        ${HEADER_FILES}
        ${SOURCES_FILES}
)


add_library(${PROJECT_NAME} STATIC ${PROJECT_SRC})


acf_create_moc(MOC_SOURCES "${HEADER_FILES}")
acf_wrap_resources(RESOURCES_FILES "${QRC_FILES}")
acf_wrap_ui(UI_SOURCES "${UI_FILES}")

target_sources(${PROJECT_NAME} PRIVATE ${MOC_SOURCES})
target_sources(${PROJECT_NAME} PRIVATE ${UI_SOURCES})
target_sources(${PROJECT_NAME} PRIVATE ${RESOURCES_FILES})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES_FILE_AUX})

set(outlibdir "${AUX_INCLUDE_DIR}/../../../Lib/${TARGETNAME}")

set_property(
	TARGET ${PROJECT_NAME}
	PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${outlibdir})

set_property(
	TARGET ${PROJECT_NAME}
	PROPERTY LIBRARY_OUTPUT_DIRECTORY ${outlibdir})

#qt5_use_modules(${PROJECT_NAME} Core Widgets Gui Xml Network XmlPatterns Svg Concurrent)
qt5_use_modules(${PROJECT_NAME} Core)

