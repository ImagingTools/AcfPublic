# For non-shadow build use lib directory inside source tree:

#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFLIBDIR})
#target_link_directories(${PROJECT_NAME} PUBLIC ${ACFSLNLIBDIR})
link_directories(${ACFLIBDIR})
link_directories(${ACFSLNLIBDIR})


#link_libraries(iqtdoc iview iqt2d iqtprm iloggui ifilegui iqtgui iwidgets)
#target_link_libraries(${PROJECT_NAME} -liqtdoc -liview -liqt2d -liqtprm -liloggui -lifilegui -liqtgui -liwidgets)
#acf_link_libraries(${PROJECT_NAME} iqtdoc iview iqt2d iqtprm iloggui ifilegui iqtgui iwidgets)


target_link_libraries(${PROJECT_NAME} iqtdoc iview iqt2d iqtprm iloggui ifilegui iqtgui iwidgets)

#list(APPEND LIST_LIBRARY iqtdoc iview iqt2d iqtprm iloggui ifilegui iqtgui iwidgets)
#list(APPEND LIST_LIBRARY iqtdoc)
#acf_add_library(${LIST_LIBRARY})
