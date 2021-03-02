#General base configuration should be included from all ACF-based projects

message(${PROJECT_NAME})
message(${PROJECT_DIR})
#message(${BINARY_DIR})


if(${PROJECT_NAME} STREQUAL "ArxcExe")
    project(Arxc LANGUAGES CXX)
else()
    project(${PROJECT_NAME} LANGUAGES CXX)
endif()

#add_compile_options(-fno-rtti)
#add_compile_options(-msse2)

set(PLATFORM_CODE i86)

#if(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL "X64")
set(PLATFORM_CODE x64)
#endif()

set(COMPILER_NAME "CMAKE")

if(APPLE)
    set(COMPILER_NAME "CLang")
endif()

if(${MSVC})
    set(COMPILER_NAME "VC")
    #	add_compile_options(/W4)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /wd4127 /wd4250 /wd4347 /wd4355 /wd4365 /wd4481 /wd4505 /wd4510 /wd4511 /wd4512 /wd4548 /wd4571 /wd4619 /wd4625 /wd4626 /wd4640 /wd4702 /wd4710 /wd4820 /wd4826")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /MP /fp:fast")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /bigobj")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /wd4718")
    if(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL X86)
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /arch:SSE2")
    endif()
    #endif()

    if(${MSVC_TOOLSET_VERSION} STREQUAL 80)
        #	message("Visual Studio 2005")
        set(COMPILER_NAME "VC8")
    endif()

    if(${MSVC_TOOLSET_VERSION} STREQUAL 90)
        #	message("Visual Studio 2008")
        set(COMPILER_NAME "VC9")
        string(REPLACE "/Gd" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
        string(REPLACE "/GD" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
        string(REPLACE "-Gd" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
        string(REPLACE "-GD" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
    endif()

    if(${MSVC_TOOLSET_VERSION} STREQUAL 100)
        #	message("Visual Studio 2010")
        set(COMPILER_NAME "VC10")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996")
    endif()

    if(${MSVC_TOOLSET_VERSION} STREQUAL 110)
        #	message("Visual Studio 2012")
        set(COMPILER_NAME "VC11")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996")
    endif()

    if(${MSVC_TOOLSET_VERSION} STREQUAL 120)
        #	message("Visual Studio 2013")
        set(COMPILER_NAME "VC12")
        add_compile_options(-std=c++11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996 /Qpar /Gy /Gw /FS")
    endif()

    if(${MSVC_TOOLSET_VERSION} STREQUAL 140)
        #	message("Visual Studio 2015")
        set(COMPILER_NAME "VC14")
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /Qpar /Gy /Gw /FS /Zc:threadSafeInit-")
        set(CMAKE_CXX_FLAGS_RELEASE_INIT "${CMAKE_CXX_FLAGS_RELEASE_INIT} /Ot /Oi /Ob2 /GS-")
        if(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL X86)
            set(CMAKE_CXX_LINK_LIBRARY_FLAG "${CMAKE_CXX_LINK_LIBRARY_FLAG} /MACHINE:X64")
        endif()
    endif()
    if(${MSVC_TOOLSET_VERSION} STREQUAL 141)
        #	message("Visual Studio 2017")
        set(COMPILER_NAME "VC15")
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /Qpar /Gy /Gw /FS /Zc:threadSafeInit-")
        set(CMAKE_CXX_FLAGS_RELEASE_INIT "${CMAKE_CXX_FLAGS_RELEASE_INIT} /Ot /Oi /Ob2 /GS-")
        if(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL X86)
            set(CMAKE_CXX_LINK_LIBRARY_FLAG "${CMAKE_CXX_LINK_LIBRARY_FLAG} /MACHINE:X64")
        endif()
    endif()
    if(${MSVC_TOOLSET_VERSION} STREQUAL 142)
        #	message("Visual Studio 2019")
        set(COMPILER_NAME "VC16")
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /Qpar /Gy /Gw /FS /Zc:threadSafeInit-")
        set(CMAKE_CXX_FLAGS_RELEASE_INIT "${CMAKE_CXX_FLAGS_RELEASE_INIT} /Ot /Oi /Ob2 /GS-")
        if(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL X86)
            set(CMAKE_CXX_LINK_LIBRARY_FLAG "${CMAKE_CXX_LINK_LIBRARY_FLAG} /MACHINE:X64")
        endif()
    endif()
    if(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL X86)
        set(COMPILER_NAME "${COMPILER_NAME}_64")
    endif()

endif()


if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()



set(COMPILER_DIR "${CMAKE_BUILD_TYPE}${COMPILER_NAME}${PLATFORM_CODE}")

#message(COMPILER_DIR)

#message(${COMPILER_DIR})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(AUXINCLUDEDIR "AuxInclude/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}/GeneratedFiles")
set(AUXINCLUDEPATH "${PROJECT_DIR}/../../${AUXINCLUDEDIR}")
set(ACF_TRANSLATIONS_OUTDIR "${AUXINCLUDEPATH}/${TARGETNAME}")
#set(AUTOGEN_BUILD_DIR "${ACF_TRANSLATIONS_OUTDIR}")

set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS Core REQUIRED)

include_directories("$ENV{QTDIR}/include/")

include_directories("$ENV{ACFDIR}/include/")
include_directories("$ENV{ACFDIR}/Impl/")

include_directories("$ENV{ACFSLNDIR}/include/")
include_directories("$ENV{ACFSLNDIR}/Impl/")

include_directories("$ENV{IACFDIR}/include/")
include_directories("$ENV{IACFDIR}/Impl/")
include_directories("${PROJECT_DIR}/../../../")
include_directories("${PROJECT_DIR}/../../")
include_directories("${PROJECT_DIR}/../")

include_directories("${INCLUDE_DIR}")
include_directories("${IMPL_DIR}")
#include_directories("${AUXINCLUDEPATH}/${PROJECT_NAME}")

#message(PROJECT_NAME)
#message("${AUXINCLUDEPATH}/${PROJECT_NAME}")

if (WIN32)
    include_directories("$ENV{QTDIR}/include/")

    include_directories("$ENV{ACFDIR}/include/")
    include_directories("$ENV{ACFDIR}/Impl/")

    include_directories("$ENV{ACFSLNDIR}/include/")
    include_directories("$ENV{ACFSLNDIR}/Impl/")

    include_directories("$ENV{IACFDIR}/include/")
    include_directories("$ENV{IACFDIR}/Impl/")

    include_directories("$ENV{LCMSDIR_2_3}/include/")

    include_directories("$ENV{LIBDC1394_2_2_0}/include/")

    include_directories("$ENV{LIVE555DIR_20121024}/include/")

    include_directories("$ENV{OPENCVDIR_3_3_1}/include/")

    include_directories("$ENV{QSCINTILLA}/Qt4Qt5/")

    include_directories("$ENV{QWT3DDIR_0_3_1}/include/")

    include_directories("$ENV{QWTDIR_6_1_2}/src/")

    include_directories("$ENV{ZLIBDIR}/include/")

    include_directories("$ENV{FFMPEGDIR_20121010}/include/")

    include_directories("$ENV{LIBDC1394_2_2_0}")

    include_directories("${PROJECT_DIR}/../../../")
    include_directories("${PROJECT_DIR}/../../")
    include_directories("${PROJECT_DIR}/../")

    include_directories("${INCLUDE_DIR}")
    include_directories("${IMPL_DIR}")
endif()

foreach(SUBDIR ${INCLUDE_DIRS})
    include_directories("${PROJECT_DIR}" "${AUX_INCLUDE_DIR}/${SUBDIR}/${SUBDIR}_autogen/include")
endforeach()

foreach(SUBDIR ${IMPL_DIRS})
    include_directories("${PROJECT_DIR}" "${AUX_INCLUDE_DIR}/${SUBDIR}/${SUBDIR}_autogen/include")
endforeach()

#file(GLOB HEADER_FILES_AUX "${AUXINCLUDEPATH}/${PROJECT_NAME}/*.h")
#file(GLOB SOURCES_FILES_AUX "${AUXINCLUDEPATH}/${PROJECT_NAME}/*.cpp")

#foreach(outfile ${SOURCES_FILES_AUX})
#    set_source_files_properties(${outfile} PROPERTIES SKIP_AUTOMOC ON)
#    set_source_files_properties(${outfile} PROPERTIES SKIP_AUTOUIC ON)
#endforeach()

#message("Test_HEADER")
#message("${AUXINCLUDEPATH}/${PROJECT_NAME}")

#file(GLOB PROJECT_SRC
#        ${HEADER_FILES}
#        ${SOURCES_FILES}
#)

file(GLOB LIBACF_LIST "${ACFLIBDIR}/*.lib")
file(GLOB LIBACFSLN_LIST "${ACFSLNLIBDIR}/*.lib")

link_directories(${ACFLIBDIR})

link_directories(${ACFSLNLIBDIR})

link_libraries(${LIBACF_LIST})
link_libraries(${LIBACFSLN_LIST})

if(${MSVC})
    link_libraries("Mpr.lib")
endif()
