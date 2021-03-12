include(${CMAKE_CURRENT_LIST_DIR}/GeneralConfig.cmake)

include_directories(${PROJECT_SOURCE_DIR}/..../../)

#file(GLOB UI_FILES "${PROJECT_SOURCE_DIR}/../*.ui")
file(GLOB HEADER_FILES "${PROJECT_SOURCE_DIR}/../*.h")
file(GLOB SOURCES_FILES "${PROJECT_SOURCE_DIR}/../*.cpp")
file(GLOB QRC_FILES "${PROJECT_SOURCE_DIR}/../*.qrc")

file(GLOB PROJECT_SRC
#    ${UI_FILES}
    ${HEADER_FILES}
    ${SOURCES_FILES}
#    ${RESOURCES_FILES}
#    ${HEADER_FILES_AUX}
#    ${SOURCES_FILES_AUX}
    ${QRC_FILES}
)
set(TARGET_EXT ".arp")

add_library(${PROJECT_NAME} ${PROJECT_SRC})

target_sources(${PROJECT_NAME} PUBLIC ${MOC_SOURCES})
target_sources(${PROJECT_NAME} PUBLIC ${UI_FILES})
target_sources(${PROJECT_NAME} PUBLIC ${RESOURCES_FILES})
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES_FILE_AUX})

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ${TARGET_EXT})

qt5_use_modules(${PROJECT_NAME} Core Widgets Gui Xml Network XmlPatterns Svg Concurrent)

set(outbindir "${AUX_INCLUDE_DIR}/../../../Bin/${TARGETNAME}")

set_property(
    TARGET ${PROJECT_NAME}
    PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${outbindir})

set_property(
    TARGET ${PROJECT_NAME}
    PROPERTY LIBRARY_OUTPUT_DIRECTORY ${outbindir})


#set(ACFDIRBUILD "${AUX_INCLUDE_DIR}/../../../Lib/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
#set(LIBRARY_OUTPUT_PATH "${ACFDIRBUILD}")

#set(ACFDIRBUILD "${AUX_INCLUDE_DIR}/../../../Bin/${TARGETNAME}")

#if(WIN32)
#    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        "${AUX_INCLUDE_DIR}/${PROJECT_NAME}/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}.arp"
#        "${ACFDIRBUILD}/${PROJECT_NAME}.arp" )
#else()
#    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        "${AUX_INCLUDE_DIR}/${PROJECT_NAME}/lib${PROJECT_NAME}.arp"
#        "${ACFDIRBUILD}/lib${PROJECT_NAME}.arp" )
#endif()
