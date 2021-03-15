# For non-shadow build use lib directory inside source tree:

#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFDIR}/Lib/${TARGETNAME})
#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFSLNDIR}/Lib/${TARGETNAME})
link_directories(${ACFDIR}/Lib/${TARGETNAME})
link_directories(${ACFSLNDIR}/Lib/${TARGETNAME})

#link_libraries(iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd)
#target_link_libraries(${PROJECT_NAME} -liqt -lipackage -lidoc -lifile -liimg -licmm -li2d -li3d -liprm -lilog -libase -licomp -liattr -liser -limod -limath -listd)
#target_link_libraries(${PROJECT_NAME} iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd)
acf_link_libraries(${PROJECT_NAME} iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd)
#if(${MSVC})
#	link_libraries("Mpr")
#endif()
