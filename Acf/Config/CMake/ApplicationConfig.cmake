include(${CMAKE_CURRENT_LIST_DIR}/QtGuiBaseConfig.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/GeneralConfig.cmake)


#file(GLOB UI_FILES "${PROJECT_SOURCE_DIR}/../*.ui")
message("PROJECT_SOURCE_DIR "  ${PROJECT_SOURCE_DIR})
message("CMAKE_PROJECT_HOMEPAGE_URL "  ${CMAKE_PROJECT_HOMEPAGE_URL})
file(GLOB HEADER_FILES "${PROJECT_SOURCE_DIR}/../*.h")
file(GLOB SOURCES_FILES "${PROJECT_SOURCE_DIR}/../*.cpp")
file(GLOB QRC_FILES "${PROJECT_SOURCE_DIR}/../*.qrc")

file(GLOB PROJECT_SRC
#    ${UI_FILES}
    ${HEADER_FILES}
    ${SOURCES_FILES}
#    ${RESOURCES_FILES}
#    ${HEADER_FILE_AUX}
#    ${SOURCES_FILE_AUX}
#    ${QRC_FILES}
)

message("SOURCES_FILE_AUX " "${SOURCES_FILE_AUX}")
#message("ACFLIBDIR " "${ACFDIR}/Lib/${TARGETNAME}")
#message("ACFSLNLIBDIR " "${ACFSLNDIR}/Lib/${TARGETNAME}")
#if(WIN32)
#	set(CMAKE_EXE_LINKER_FLAGS "/MANIFEST:NO /DEBUG:FULL /LIBPATH:${ACFDIR}/Lib/${TARGETNAME} /LIBPATH:${ACFSLNDIR}/Lib/${TARGETNAME} /VERBOSE /SUBSYSTEM:WINDOWS")
#	add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SRC})
#else()
#	add_executable(${PROJECT_NAME} ${PROJECT_SRC})
#endif()

set(CMAKE_EXE_LINKER_FLAGS "/MANIFEST:NO /DEBUG:FULL /LIBPATH:${ACFDIR}/Lib/${TARGETNAME} /LIBPATH:${ACFSLNDIR}/Lib/${TARGETNAME} /VERBOSE /SUBSYSTEM:WINDOWS")
add_executable(${PROJECT_NAME} ${PROJECT_SRC})

#target_include_directories(${PROJECT_NAME} PUBLIC ${AUX_INCLUDE_DIR})
#target_include_directories(${PROJECT_NAME} PRIVATE ${ACFSLNLIBGLOBDIR})
#target_sources(${PROJECT_NAME} PUBLIC ${HEADER_FILE_AUX} ${SOURCES_FILE_AUX})
#target_sources(${PROJECT_NAME} PUBLIC ${SOURCES_FILE_AUX})
#target_sources(${PROJECT_NAME} PUBLIC ${RESOURCES_FILES})
#target_sources(${PROJECT_NAME} PUBLIC ${HEADER_FILE_AUX} ${SOURCES_FILE_AUX})
#target_sources(${PROJECT_NAME} PUBLIC ${UI_FILES})
#target_sources(${PROJECT_NAME} PUBLIC ${RESOURCES_FILES})
#add_dependencies(${PROJECT_NAME} ARXC${PROJECT_NAME})
target_sources(${PROJECT_NAME} PUBLIC ${MOC_SOURCES})
target_sources(${PROJECT_NAME} PUBLIC ${UI_FILES})
target_sources(${PROJECT_NAME} PUBLIC ${RESOURCES_FILES})
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES_FILE_AUX})
target_sources(${PROJECT_NAME} PUBLIC ${RC_FILE})

#if(${RESOURCES_FILES_CHECK} STREQUAL "1")
#    message(RESOURCES_FILES_CHECK)
#    add_dependencies(${PROJECT_NAME} resources${PROJECT_NAME})
#endif()
#if(NOT ${PROJECT_NAME} STREQUAL "Arxc")
#	add_dependencies(${PROJECT_NAME} Arxc)
#endif()

qt5_use_modules(${PROJECT_NAME} Core Widgets Gui Xml Network XmlPatterns Svg Concurrent)

set(outbindir "${AUX_INCLUDE_DIR}/../../../Bin/${TARGETNAME}")
set_property(
    TARGET ${PROJECT_NAME}
    PROPERTY RUNTIME_OUTPUT_DIRECTORY ${outbindir})

#set(EXECUTABLE_OUTPUT_PATH "${ACFDIRBUILD}")

#set(ACFDIRBUILD "${AUX_INCLUDE_DIR}/../../../Bin/${TARGETNAME}")

#if(WIN32)
#    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        "${AUX_INCLUDE_DIR}/${PROJECT_NAME}/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}.exe"
#        "${ACFDIRBUILD}/${PROJECT_NAME}.exe" )
#else()
#    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        "${AUX_INCLUDE_DIR}/${PROJECT_NAME}/${PROJECT_NAME}"
#        "${ACFDIRBUILD}/${PROJECT_NAME}" )
#endif()
