cmake_minimum_required(VERSION 2.8)
PROJECT(tinylist_test)

MESSAGE(STATUS "TinyList")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CUSTOM_LIBRARY_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories(${CMAKE_BINARY_DIR}/include)
link_directories(${CMAKE_BINARY_DIR}/lib)

add_definitions(-D_GLIBCXX_USE_NANOSLEEP)
add_executable(tinylist_test tinylist_test.cpp)
target_link_libraries(tinylist_test ${CUSTOM_LIBRARY_PATH}/libtinylist.a)