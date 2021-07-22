project(istd LANGUAGES CXX)

include(${ACFDIR}/Config/CMake/StaticConfig.cmake)


if(${APPLE})
	if("${CMAKE_OSX_ARCHITECTURES}" STREQUAL "arm64")
		target_compile_definitions(${PROJECT_NAME} PRIVATE COMPILER_NAME=ClangOSX)
		target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_CODE=arm64)
	else()
		target_compile_definitions(${PROJECT_NAME} PRIVATE COMPILER_NAME=ClangOSX)
		target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_CODE=x64)
	endif()

elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		target_compile_definitions(${PROJECT_NAME} PRIVATE COMPILER_NAME=GCCLinux)
	else()
		target_compile_definitions(${PROJECT_NAME} PRIVATE COMPILER_NAME=ClangLinux)
	endif()
	target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_CODE=x64)
endif()
