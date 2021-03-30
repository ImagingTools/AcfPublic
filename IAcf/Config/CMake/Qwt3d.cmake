include_directories("$ENV{QWT3DDIR_0_3_1}/include")
#INCLUDEPATH += "$(QWT3DDIR_0_3_1)/Include"
#target_link_directories(${PROJECT_NAME} PUBLIC $ENV{QWT3DDIR_0_3_1}/Lib/${TARGETNAME})
link_directories($ENV{QWT3DDIR_0_3_1}/Lib/${TARGETNAME})

target_link_libraries(${PROJECT_NAME} qwt3d)
#LIBS += -L$(QWT3DDIR_0_3_1)/Lib/$$COMPILER_DIR -lqwt3d
