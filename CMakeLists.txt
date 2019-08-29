cmake_minimum_required(VERSION 3.13)
project(testCpp)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(CMAKE_CXX_STANDARD 14)
#find_package(PythonLibs)
#include_directories(${PYTHON_INCLUDE_DIRS})

#find_package(PythonLibs 2.7)

#add_executable(testCpp main.cpp plots.cpp plots.h threads.cpp threads.h randon.cpp randon.h pthreads.cpp pthreads.h timetest.cpp timetest.h)
#target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARY})
#target_include_directories(${PROJECT_NAME}  PRIVATE ${PYTHON_INCLUDE_DIRS})
#target_link_libraries(${PROJECT_NAME}  ${PYTHON_LIBRARIES})

add_executable(testCpp main.cpp Memory_alocation.cpp)