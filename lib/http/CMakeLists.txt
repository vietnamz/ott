# minimun requirements
# my cmake cmake version 3.14.5
cmake_minimum_required(VERSION 3.14.5)
#project name
project(packager_lib)
# mark the cpp files as sources.
file(GLOB SOURCES "src/*.cpp")

# set cmake variables.
#set( CMAKE_CXX_FLAGS "-Wall -m64 -O3 -std=c++17")
#set( UTIL_HTTP libhttp.a)
#set(Boost_USE_STATIC_LIBS        ON) # only find static libs
#set(Boost_USE_MULTITHREADED      ON)
#set(Boost_USE_STATIC_RUNTIME    OFF)
#find_package(Boost 1.73.0 COMPONENTS date_time filesystem system thread)
#if(Boost_FOUND)
#    message("Found Boost lib")
#    message(${Boost_INCLUDE_DIRS})
    #message(${Boost_LIBRARIES})
    #    include_directories(${Boost_INCLUDE_DIRS})
    #link_directories(${Boost_LIBRARY_DIRS})
    #endif()
#link the third party libs
#link_directories(/usr/local/lib/)

add_library(http SHARED ${SOURCES})

#include_directories(/usr/local/include)
#include_directories(~/src/)
message(${Boost_INCLUDE_DIRS})
message(${Boost_LIB_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIB_DIRS})
link_directories(/usr/local/opt/openssl/lib/)
#add_executable(testHttp test/test.cpp)
#add_executable(test_1 test/http_server_sync_ssl.cpp)
#add_executable(test_client test/test_client.cpp)
#target_link_libraries(testHttp http ${Boost_LIBRARIES})
#target_link_libraries(test_1 http ${Boost_LIBRARIES})
#target_link_libraries(test_client http ${Boost_LIBRARIES})


