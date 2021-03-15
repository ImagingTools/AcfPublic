project(iservice LANGUAGES CXX)


include(${ACFDIR}/Config/CMake/QtGuiBaseConfig.cmake)
include(${ACFDIR}/Config/CMake/GeneralConfig.cmake)


#file(GLOB PROJECT_SRC
#        "${PROJECT_SOURCE_DIR}/../CServiceApplicationComp.h"
#        "${PROJECT_SOURCE_DIR}/../CServiceApplicationComp.cpp"
#        "${PROJECT_SOURCE_DIR}/../qtservice.h"
#        "${PROJECT_SOURCE_DIR}/../qtservice.cpp"
#        "${PROJECT_SOURCE_DIR}/../qtservice_win.h"
#        "${PROJECT_SOURCE_DIR}/../qtservice_win.cpp"
#        "${PROJECT_SOURCE_DIR}/../qtservicestarter.h"
#        "${PROJECT_SOURCE_DIR}/../qtservicestarter.cpp"
#)
file(GLOB PROJECT_SRC
        "${PROJECT_SOURCE_DIR}/../CServiceApplicationComp.h"
        "${PROJECT_SOURCE_DIR}/../CServiceApplicationComp.cpp"
)

if (WIN32)
    add_compile_options(/utf-8)
    ADD_DEFINITIONS(-DUNICODE)
    ADD_DEFINITIONS(-D_UNICODE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /UMBCS /D_UNICODE /DUNICODE")
    file(GLOB PROJECT_SRC
            "${PROJECT_SOURCE_DIR}/../qtservice.h"
            "${PROJECT_SOURCE_DIR}/../qtservice.cpp"
            "${PROJECT_SOURCE_DIR}/../qtservice_win.h"
            "${PROJECT_SOURCE_DIR}/../qtservice_win.cpp"
            "${PROJECT_SOURCE_DIR}/../qtservicestarter.h"
            "${PROJECT_SOURCE_DIR}/../qtservicestarter.cpp"
    )
endif()

#set(TARGET_EXT ".lib")

add_library(${PROJECT_NAME} STATIC ${PROJECT_SRC})

#set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ${TARGET_EXT})
set_property(
    TARGET ${PROJECT_NAME}
	PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${ACFDIR}/Lib/${TARGETNAME})

set_property(
    TARGET ${PROJECT_NAME}
	PROPERTY LIBRARY_OUTPUT_DIRECTORY ${ACFDIR}/Lib/${TARGETNAME})

qt5_use_modules(${PROJECT_NAME} Core Widgets Gui Xml Network XmlPatterns Svg Concurrent)


