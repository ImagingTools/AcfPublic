
if(WIN32)
    set(ARX_COMPILER "Arxc.exe")
    set(ACF_TOOL "Acf.exe")
    set(QMAKE_RCC "rcc.exe")
    set(COPY_FILE "copy")
else()
    set(ARX_COMPILER "Arxc")
    set(ACF_TOOL "Acf")
    set(QMAKE_RCC "rcc")
    set(COPY_FILE "cp")
endif()

set(PROJECT_BINARY_DIR ${AUX_INCLUDE_DIR}/${PROJECT_NAME})
message("PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})

set(ACFTOOLS "$ENV{ACFDIR}/../AcfTools")

set(ARXCBIN "${ACFBINDIR}/${ARX_COMPILER}")
set(ACFBIN "${ACFBINDIR}/${ACF_TOOL}")

set(ARXC_OUTFILE_NANE C${PROJECT_NAME}.cpp)
set(ARXC_OUTFILE_PATH ${ARXC_OUTDIR}/GeneratedFiles/${PROJECT_NAME}/${ARXC_OUTFILE_NANE})

add_custom_command(OUTPUT ${ARXC_OUTFILE_NANE}
    COMMAND ${ARXCBIN}
    ARGS ${ARXC_FILES} -o ${ARXC_OUTFILE_NANE} -config ${ARXC_CONFIG} -conf_name ${TARGETNAME}_64 -env_vars ${ENV_VARS} -v
    DEPENDS Arxc VERBATIM)

#MAIN_DEPENDENCY ${ARXC_FILES} VERBATIM)
message("Arxc generated: ${ARXCBIN} ${ARXC_FILES} -o ${ARXC_OUTFILE_NANE} -config ${ARXC_CONFIG} -conf_name ${TARGETNAME}_64 -env_vars ${ENV_VARS} -v" )

add_custom_target(ARXC${PROJECT_NAME} ALL DEPENDS ${ARXC_OUTFILE_NANE})

set(HEADER_FILE_AUX "${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.h")
set(SOURCES_FILE_AUX "${ARXC_OUTDIR}/${PROJECT_NAME}/C${PROJECT_NAME}.cpp")

set_property(SOURCE ${SOURCES_FILE_AUX} PROPERTY SKIP_AUTOMOC ON)
set_property(SOURCE ${HEADER_FILE_AUX} PROPERTY SKIP_AUTOMOC ON)

