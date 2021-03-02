if(WIN32)
    set(ARX_COMPILER "Arxc.exe")
#    set(ARX_COMPILER "Acf.exe")
    set(ACF_TOOL "Acf.exe")
    set(QMAKE_RCC "rcc.exe")
    set(COPY_FILE "copy")
else()
    set(ARX_COMPILER "Arxc")
    set(ACF_TOOL "Acf")
    set(QMAKE_RCC "rcc")
    set(COPY_FILE "cp")
endif()

set(ACFTOOLS "$ENV{ACFDIR}/../AcfTools")

#if(APPLE)
#    if(${ACFTOOLS} STREQUAL "")
#    else()
#        set(ARX_COMPILER "Arxc.app/Contents/MacOS/Arxc")
#    endif()
#endif()

#if(${ACFTOOLS} STREQUAL "")
#    if(${ACFDIRBUILD} STREQUAL "")
set(ARXCBIN "${ACFBINDIR}/${ARX_COMPILER}")
set(ACFBIN "${ACFBINDIR}/${ACF_TOOL}")
#set(ARXCBIN "Arxc.exe")

message("ARXCBIN")
message("${ARXCBIN}")
#    else()
#        set(ARXCBIN "${ACFDIRBUILD}/Bin/${TARGETNAME}/${ARX_COMPILER}")
#        set(ACFBIN "${ACFDIRBUILD}/Bin/${TARGETNAME}/${ACF_TOOL}")
#    endif()
#else()
#    set(ARXCBIN "${ACFTOOLS}/${QMAKE_HOST.os}/${ARX_COMPILER}")
#    set(ACFBIN "${ACFTOOLS}/${QMAKE_HOST.os}/${ACF_TOOL}")
#endif()

#if(WIN32)
#    set(ARXCBIN ~= "s,/,\\,g")
#    set(ACFBIN ~= "s,/,\\,g")
#endif()

#set(ARX_COMPILER_OUTPUT "${ARXC_OUTDIR} /C ${PROJECT_SRC} ${ARXC_OUTDIR} /C ${PROJECT_SRC}")

set(ARX_COMPILER_COMMAND "${ARXCBIN} ${ARXC_FILES} -o ${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.h ${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.cpp -config ${ARXC_CONFIG} -conf_name ${TARGETNAME}_64 -env_vars ${ENV_VARS} -v")
message(${ARX_COMPILER_COMMAND})
#add_custom_target(ARXC${PROJECT_NAME} ALL ${ARX_COMPILER_COMMAND}
#    DEPENDS Arxc
#    VERBATIM)
#list(APPEND ARGS_ARXC ${ARXC_FILES} -o ${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.h ${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.cpp -config ${ARXC_CONFIG} -conf_name ${TARGETNAME}_64 -env_vars ${ENV_VARS} -v)
#set(ARX_OUT "${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.h ${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.cpp")

#add_custom_command(
##    OUTPUT "${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.h ${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.cpp"
##OUTPUT ${ARX_OUT}
##COMMAND ${ARXCBIN} -config ${ARXC_CONFIG} -conf_name ${TARGETNAME}_64 -env_vars ${ENV_VARS} -v
##TARGET  ARXC${PROJECT_NAME}
##COMMAND ${ARXCBIN} ${ARGS_ARXC}
# COMMAND ${CMAKE_COMMAND} -E echo bar:hello
#WORKING_DIRECTORY ${ARXC_OUTDIR}

##  DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/libfoo/foo.tar"
#  COMMENT "ARX_OUT test"
#  VERBATIM
#)


list(APPEND ARGS_ARXC ${ARXC_FILES} -o ${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.cpp ${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.h -config ${ARXC_CONFIG} -conf_name ${TARGETNAME}_64 -env_vars ${ENV_VARS} -v)

#add_custom_target(ARXC${PROJECT_NAME} ALL
#    COMMAND ${ARXCBIN}
##    ${ARGS_ARXC}
#    DEPENDS Arxc
#    VERBATIM)
#message(${ARXC_OUTDIR})

#add_subdirectory(src)
#add_subdirectory(tests)

# Run code generation
execute_process(COMMAND ${ARXCBIN} ${ARGS_ARXC})

set(HEADER_FILES_AUX ${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.h)
set(SOURCES_FILES_AUX ${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.cpp)

## src/CMakeLists.txt
#add_custom_command(
#    OUTPUT "${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.cpp"
##    COMMAND sleep 1
##COMMAND cmake -E echo Hello
##> gen
#    COMMAND ${ARXCBIN} ${ARGS_ARXC}
#    )

#add_custom_target(
#    ARXC${PROJECT_NAME} ALL DEPENDS "${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.cpp"
#    )



#add_custom_target(
#    my-all-2 ALL DEPENDS gen
#    )


#add_custom_target(ARXC${PROJECT_NAME} ALL
#    COMMAND ${ARXCBIN} ${ARGS_ARXC}
#    DEPENDS Arxc
#    VERBATIM)
message("${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.h")
#file(GLOB HEADER_FILES_ARX "${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.h")
#file(GLOB SOURCES_FILES_ARX "${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.cpp")
#set(HEADER_FILES_ARX "${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.h")
#set(SOURCES_FILES_ARX "${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.cpp")

