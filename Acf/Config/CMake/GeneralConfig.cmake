#General base configuration should be included from all ACF-based projects

message("PROJECT_NAME " ${PROJECT_NAME})
message("CMAKE_CURRENT_LIST_DIR " ${CMAKE_CURRENT_LIST_DIR})
message("PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
message("BINARY_DIR " ${BINARY_DIR})
#set(PROJECT_BINARY_DIR ${AUX_INCLUDE_DIR}/${PROJECT_NAME})
#message("PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})

#if(${PROJECT_NAME} STREQUAL "ArxcExe")
#    project(Arxc LANGUAGES CXX)
#else()
#    project(${PROJECT_NAME} LANGUAGES CXX)
#endif()

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

	# Qt-BUG 31516. Remove it after the fix in Qt!!!
	set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /wd4718")
	if(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL x64)
		set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /arch:SSE2")
	endif()
#message("CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS})

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
			message("CMAKE_CXX_LINK_LIBRARY_FLAG " ${CMAKE_CXX_LINK_LIBRARY_FLAG})
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
#	if(${CMAKE_CXX_COMPILER_ARCHITECTURE_ID} STREQUAL X86)
#        set(COMPILER_NAME "${COMPILER_NAME}_64")
#    endif()
    if(${CMAKE_CL_64} STREQUAL 1)
		set(COMPILER_NAME "${COMPILER_NAME}_64")
	endif()

endif()

message("CMAKE_CXX_COMPILER_ARCHITECTURE_ID " "${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}")
#if(CMAKE_VERSION VERSION_LESS "3.7.0")
#    set(CMAKE_INCLUDE_CURRENT_DIR ON)
#endif()



set(COMPILER_DIR "${CMAKE_BUILD_TYPE}${COMPILER_NAME}${PLATFORM_CODE}")

#message(COMPILER_DIR)

#message(${COMPILER_DIR})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(AUXINCLUDEDIR "AuxInclude/Qt${QT_DEFAULT_MAJOR_VERSION}_${TARGETNAME}/GeneratedFiles")
set(AUXINCLUDEPATH "${PROJECT_SOURCE_DIR}/../../../${AUXINCLUDEDIR}")
set(ACF_TRANSLATIONS_OUTDIR "${AUXINCLUDEPATH}/${TARGETNAME}")
#set(AUTOGEN_BUILD_DIR "${ACF_TRANSLATIONS_OUTDIR}")

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS Core REQUIRED)

include_directories("${PROJECT_SOURCE_DIR}/../../")
#include_directories("${PROJECT_SOURCE_DIR}/../")

#include_directories("${CMAKE_CURRENT_LIST_DIR}/../../Include")
#include_directories("${CMAKE_CURRENT_LIST_DIR}/../../Impl")
include_directories("${INCLUDE_DIR}")
include_directories("${IMPL_DIR}")


file(GLOB HEADER_FILES "${PROJECT_SOURCE_DIR}/../*.h")

if(QT_DEFAULT_MAJOR_VERSION EQUAL 5)
	qt5_wrap_cpp(MOC_SOURCES ${HEADER_FILES} )
elseif(QT_DEFAULT_MAJOR_VERSION EQUAL 6)
	qt6_wrap_cpp(MOC_SOURCES ${HEADER_FILES} )
endif()

#qt5_wrap_cpp(MOC_SOURCES)

function(acf_link_libraries target)
	set(outfiles)
	foreach(it ${ARGN})
		if(WIN32)
			list(APPEND outfiles "${it}.lib")
		else()
			list(APPEND outfiles "lib${it}.a")
		endif()
	endforeach()
#	message("outfiles: " ${outfiles})
	target_link_libraries(${target} ${outfiles})
endfunction()

#message("${MOC_SOURCES}")
link_directories(${ACFDIR}/Lib/${TARGETNAME})
link_directories(${ACFSLNDIR}/Lib/${TARGETNAME})


if(${MSVC})
    link_libraries("Mpr.lib")
endif()

