include(${CMAKE_CURRENT_LIST_DIR}/GeneralConfig.cmake)

include_directories(${PROJECT_SOURCE_DIR}/..../../)

file(GLOB UI_FILES "${PROJECT_SOURCE_DIR}/../*.ui")
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

add_library(${PROJECT_NAME} SHARED ${PROJECT_SRC})
#add_library(${PROJECT_NAME} STATIC ${PROJECT_SRC})

#acf_create_moc("${HEADER_FILES}")

##target_sources(${PROJECT_NAME} PUBLIC ${MOC_SOURCES})
#target_sources(${PROJECT_NAME} PUBLIC ${UI_FILES})
#target_sources(${PROJECT_NAME} PUBLIC ${RESOURCES_FILES})

acf_create_moc(MOC_SOURCES "${HEADER_FILES}")
acf_wrap_resources(RESOURCES_FILES "${QRC_FILES}")
acf_wrap_ui(UI_SOURCES "${UI_FILES}")

target_sources(${PROJECT_NAME} PRIVATE ${MOC_SOURCES})
target_sources(${PROJECT_NAME} PRIVATE ${UI_SOURCES})
target_sources(${PROJECT_NAME} PRIVATE ${RESOURCES_FILES})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES_FILE_AUX})

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ${TARGET_EXT})

qt5_use_modules(${PROJECT_NAME} Core Widgets Gui Xml Network XmlPatterns Svg Concurrent)
#qt5_use_modules(${PROJECT_NAME} Core)

set(outbindir "${AUX_INCLUDE_DIR}/../../../Bin/${TARGETNAME}")

#set_property(
#    TARGET ${PROJECT_NAME}
#    PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${outbindir})

#set_property(
#    TARGET ${PROJECT_NAME}
#    PROPERTY LIBRARY_OUTPUT_DIRECTORY ${outbindir})


#set(ACFDIRBUILD "${AUX_INCLUDE_DIR}/../../../Lib/${TARGETNAME}")
set(LIBRARY_OUTPUT_PATH "${outbindir}")

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
