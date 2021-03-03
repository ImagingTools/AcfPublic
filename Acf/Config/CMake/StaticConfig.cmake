include(${CMAKE_CURRENT_LIST_DIR}/GeneralConfig.cmake)

#if(${QT_DEFAULT_MAJOR_VERSION} STREQUAL 5)
##	message("COMPONENTS Widgets")
#        find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS Widgets REQUIRED)
#endif()

file(GLOB UI_FILES "${PROJECT_DIR}/*.ui")
file(GLOB HEADER_FILES "${PROJECT_DIR}/*.h")
file(GLOB SOURCES_FILES "${PROJECT_DIR}/*.cpp")
file(GLOB QRC_FILES "${PROJECT_DIR}/*.qrc")

file(GLOB PROJECT_SRC
        ${UI_FILES}
        ${HEADER_FILES}
        ${SOURCES_FILES}
        ${RESOURCES_FILES}
        ${HEADER_FILES_AUX}
        ${SOURCES_FILES_AUX}
        ${QRC_FILES}
)

#message("SOURCES_FILES_AUX")
#message("${SOURCES_FILES_AUX}")
#set(TARGET_EXT ".lib")

add_library(${PROJECT_NAME} STATIC ${PROJECT_SRC})

#set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ${TARGET_EXT})
#set_target_properties(${PROJECT_NAME} PROPERTIES AUTOGEN_BUILD_DIR "${ACF_TRANSLATIONS_OUTDIR}")
set(outlibdir "${AUX_INCLUDE_DIR}/../../../Lib/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")

set_property(
    TARGET ${PROJECT_NAME}
    PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${outlibdir})

set_property(
    TARGET ${PROJECT_NAME}
    PROPERTY LIBRARY_OUTPUT_DIRECTORY ${outlibdir})

qt5_use_modules(${PROJECT_NAME} Core Widgets Gui Xml Network XmlPatterns Svg Concurrent)

#set(LIBRARY_OUTPUT_PATH "${ACFDIRBUILD}")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${ACFDIRBUILD}")

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ACFDIRBUILD}")


#install(DIRECTORY DESTINATION ${ACFDIRBUILD})

#if(WIN32)
#    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        "${AUX_INCLUDE_DIR}/${PROJECT_NAME}/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}.lib"
#        "${ACFDIRBUILD}/${PROJECT_NAME}.lib" )

#else()
#    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        "${AUX_INCLUDE_DIR}/${PROJECT_NAME}/lib${PROJECT_NAME}.a"
#        "${ACFDIRBUILD}/lib${PROJECT_NAME}.a" )
#endif()
