# minimun requirements
# my cmake cmake version 3.14.5
cmake_minimum_required(VERSION 3.14.5)
#project name
project(packager_lib)
# mark the cpp files as sources.
file(GLOB SOURCES "src/*.cpp")

# set cmake variables.
set( CMAKE_CXX_FLAGS "-Wall -m64 -O3 -std=c++17")
set( UTIL_LIB libutil.a)

#find_package(Boost 1.73.0)
#if(Boost_FOUND)
#    message("Found Boost lib")
#    message(${Boost_INCLUDE_DIRS})
#endif()
#link the third party libs
link_directories(${Boost_LIB_DIRS})

add_library(util STATIC ${SOURCES})

include_directories(/usr/local/include)
include_directories(~/src/)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(test test/test.cpp)

target_link_libraries(test util boost_log boost_log_setup boost_thread)

