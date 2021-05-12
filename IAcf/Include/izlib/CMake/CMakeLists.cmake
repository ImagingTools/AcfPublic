 if(DEFINED ENV{ZLIBDIR})
		set(ZLIBDIR $ENV{ZLIBDIR})
	else()
		set(ZLIBDIR "${ACFDIR}/../3rdParty/quazip")
	endif()

include_directories(${ZLIBDIR}/include)

target_link_libraries(${PROJECT_NAME} ${ZLIBDIR}/lib/${CMAKE_BUILD_TYPE}${TARGETNAME}/zlib.lib)
