include_directories("$ENV{QWTDIR_6_1_2}/src")
#INCLUDEPATH += $(QWTDIR_6_1_2)/src

target_link_directories(${PROJECT_NAME} PUBLIC $ENV{QWTDIR_6_1_2}/Lib/${TARGETNAME})
target_link_libraries(${PROJECT_NAME} qwt)
#LIBS += -L$(QWTDIR_6_1_2)/lib/$$COMPILER_DIR -lqwt
