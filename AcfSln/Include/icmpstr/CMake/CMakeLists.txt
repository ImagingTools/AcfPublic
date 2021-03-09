project(icmpstr LANGUAGES CXX)

include(${CONFIG_DIR}/QtGuiBaseConfig.cmake)
include(${CONFIG_DIR}/StaticConfig.cmake)

find_package("Qt${QT_DEFAULT_MAJOR_VERSION}" COMPONENTS PrintSupport REQUIRED)
