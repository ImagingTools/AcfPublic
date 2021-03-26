project(QwtPck LANGUAGES CXX)

include(${ACFDIR}/Config/CMake/ComponentConfig.cmake)
include(${ACFDIR}/Config/CMake/AcfStd.cmake)
include(${ACFDIR}/Config/CMake/AcfQt.cmake)
include(${ACFDIR}/Config/CMake/QtBaseConfig.cmake)
include(../../../Config/CMake/Qwt.cmake)
include(../../../Config/CMake/Qwt3d.cmake)

target_link_directories(${PROJECT_NAME} PUBLIC ../../../Lib/${TARGETNAME})
acf_link_libraries(${PROJECT_NAME} iqwt iqwt3d)
#target_link_directories(${PROJECT_NAME} PUBLIC ${COMPILER_DIR}/Lib/${TARGETNAME})
#target_link_libraries(${PROJECT_NAME} iprm)


if(WIN32)
	target_link_libraries(${PROJECT_NAME} opengl32 glu32)
endif()

qt5_use_modules(${PROJECT_NAME} Core Widgets OpenGL Gui)

