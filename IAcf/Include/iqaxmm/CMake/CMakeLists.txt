project(iqaxmm LANGUAGES CXX)


include(${ACFDIR}/Config/CMake/StaticConfig.cmake)


#include_directories("${Qt5_DIR}/../../../include/ActiveQt")

#qt5_use_modules(${PROJECT_NAME} Axcontainer Multimedia )
#find_package(Qt6 COMPONENTS AxContainer REQUIRED)
#target_link_libraries(mytarget PRIVATE Qt6::AxContainer)
find_package("Qt${QT_VERSION_MAJOR}" COMPONENTS AxContainer REQUIRED)
target_link_libraries(${PROJECT_NAME}  Qt${QT_VERSION_MAJOR}::AxContainer)
