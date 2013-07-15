project(bunsan_network)

include(${CMAKE_SOURCE_DIR}/system-config.cmake OPTIONAL)

cmake_minimum_required(VERSION 2.8)

include(BunsanCommon)

bunsan_use_bunsan(common)
bunsan_use_xmlrpc(c++2 libwww-client abyss-server)
bunsan_use(zmq)
bunsan_use_boost(system filesystem serialization thread)

bunsan_add_shared_library(${PROJECT_NAME}
    src/zmq.cpp
    src/base64.cpp
    src/xmlrpc_service.cpp
    src/complex_service.cpp
    src/pseudo_service.cpp
)

bunsan_install_headers()
bunsan_install_targets(${PROJECT_NAME})

bunsan_include_tests()
