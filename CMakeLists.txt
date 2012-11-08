project(bunsan_network)

include(${CMAKE_SOURCE_DIR}/system-config.cmake OPTIONAL)

cmake_minimum_required(VERSION 2.8)

include(BunsanCommon)

include_directories(include)

# bunsan::common
list(APPEND libraries bunsan_common)

# XMLRPC
find_package(XMLRPC REQUIRED c++2 libwww-client abyss-server)
include_directories(${XMLRPC_INCLUDE_DIRS})
list(APPEND libraries ${XMLRPC_LIBRARIES})

# ZMQ
list(APPEND libraries zmq)

bunsan_use_boost(system filesystem serialization unit_test_framework thread)

add_library(${PROJECT_NAME} SHARED
    src/zmq.cpp
    src/base64.cpp
    src/xmlrpc_service.cpp
    src/complex_service.cpp
    src/pseudo_service.cpp
)
target_link_libraries(${PROJECT_NAME} ${libraries})

install(DIRECTORY include DESTINATION .)
bunsan_install_targets(${PROJECT_NAME})

bunsan_include_tests()
