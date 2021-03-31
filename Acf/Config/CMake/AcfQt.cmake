# For non-shadow build use lib directory inside source tree:

#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFDIR}/Lib/${TARGETNAME})
#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFSLNDIR}/Lib/${TARGETNAME})
#link_directories(${ACFDIR}/Lib/${TARGETNAME})
#link_directories(${ACFSLNDIR}/Lib/${TARGETNAME})


#link_libraries(iqtdoc iview iqt2d iqtprm iloggui ifilegui iqtgui iwidgets)
#target_link_libraries(${PROJECT_NAME} -liqtdoc -liview -liqt2d -liqtprm -liloggui -lifilegui -liqtgui -liwidgets)
#acf_link_libraries(${PROJECT_NAME} iqtdoc iview iqt2d iqtprm iloggui ifilegui iqtgui iwidgets)


target_link_libraries(${PROJECT_NAME} iqtdoc iview iqt2d iqtprm iloggui ifilegui iqtgui iwidgets)

#list(APPEND LIST_LIBRARY iqtdoc iview iqt2d iqtprm iloggui ifilegui iqtgui iwidgets)
#list(APPEND LIST_LIBRARY iqtdoc)
#acf_add_library(${LIST_LIBRARY})
