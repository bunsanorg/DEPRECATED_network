cmake_minimum_required(VERSION 3.0)

include(${CMAKE_SOURCE_DIR}/system-config.cmake OPTIONAL)

project(bunsan_network)

find_package(BunsanCMake CONFIG REQUIRED)

bunsan_add_library(${PROJECT_NAME}
    src/xmlrpc_service.cpp
    src/complex_service.cpp
    src/pseudo_service.cpp
)
bunsan_use_bunsan_package(${PROJECT_NAME} bunsan_common bunsan_common)
target_link_libraries(${PROJECT_NAME} PUBLIC zmq)
bunsan_use_boost(${PROJECT_NAME} serialization thread)
bunsan_use_package(${PROJECT_NAME} XMLRPC c++2 libwww-client abyss-server)

bunsan_install_headers()
bunsan_install_targets(${PROJECT_NAME})
bunsan_install_project()

bunsan_include_tests()
