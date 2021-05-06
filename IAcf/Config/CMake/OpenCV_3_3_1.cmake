include_directories("$ENV{OPENCVDIR_3_3_1}/include")

#target_link_directories(${PROJECT_NAME} PRIVATE $ENV{OPENCVDIR_3_3_1}/lib/${TARGETNAME})

if(WIN32)

	if(CMAKE_BUILD_TYPE EQUAL "Relase")
#	target_link_libraries(${PROJECT_NAME} -lopencv_highgui331 -lopencv_core331 -lopencv_features2d331 -lopencv_objdetect331 -lopencv_imgproc331 -lopencv_videoio331 -lopencv_imgcodecs331 -lopencv_calib3d331 -lopencv_photo331)
	target_link_libraries(${PROJECT_NAME} opencv_highgui331 opencv_core331 opencv_features2d331 opencv_objdetect331 opencv_imgproc331 opencv_videoio331 opencv_imgcodecs331 opencv_calib3d331 opencv_photo331)
    else()
#		target_link_libraries(${PROJECT_NAME} -lopencv_highgui331d -lopencv_core331d -lopencv_features2d331d -lopencv_objdetect331d -lopencv_imgproc331d -lopencv_videoio331d -lopencv_imgcodecs331d -lopencv_calib3d331d -lopencv_photo331d)
        target_link_libraries(${PROJECT_NAME} opencv_highgui331d opencv_core331d opencv_features2d331d opencv_objdetect331d opencv_imgproc331d opencv_videoio331d opencv_imgcodecs331d opencv_calib3d331d opencv_photo331d)
	endif()
else()
#unix
    target_link_libraries(${PROJECT_NAME} -lopencv_highgui -lopencv_core -lopencv_features2d -lopencv_objdetect -lopencv_imgproc -lopencv_videoio -lopencv_imgcodecs -lopencv_calib3d -lopencv_photo331)
endif()
