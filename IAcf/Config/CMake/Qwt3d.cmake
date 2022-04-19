include_directories("$ENV{QWT3DDIR_0_3_2}/include")

#target_link_directories(${PROJECT_NAME} PUBLIC $ENV{QWT3DDIR_0_3_2}/Lib/${CMAKE_BUILD_TYPE}_${TARGETNAME})

#target_link_libraries(${PROJECT_NAME} qwtplot3d)
target_link_libraries(${PROJECT_NAME} $ENV{QWT3DDIR_0_3_2}/lib/${CMAKE_BUILD_TYPE}_${TARGETNAME}/qwtplot3d.lib)

