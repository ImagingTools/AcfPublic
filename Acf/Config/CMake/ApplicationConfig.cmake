include(${CMAKE_CURRENT_LIST_DIR}/QtGuiBaseConfig.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/GeneralConfig.cmake)

if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "/MANIFEST:NO /DEBUG:FULL /LIBPATH:${ACFLIBDIR} /LIBPATH:${ACFSLNLIBDIR} /VERBOSE /SUBSYSTEM:WINDOWS")
endif()

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

message("SOURCES_FILES_AUX")
message("${SOURCES_FILES_AUX}")

add_executable(${PROJECT_NAME} ${PROJECT_SRC})

qt5_use_modules(${PROJECT_NAME} Core Widgets Gui Xml Network XmlPatterns Svg Concurrent)

set(ACFDIRBUILD "${AUX_INCLUDE_DIR}/../../../Bin/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}")
set_property(
    TARGET ${PROJECT_NAME}
    PROPERTY RUNTIME_OUTPUT_DIRECTORY ${ACFDIRBUILD})

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
