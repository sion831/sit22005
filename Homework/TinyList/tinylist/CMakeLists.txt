cmake_minimum_required(VERSION 2.8)
PROJECT(tinylist)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(INCLUDE_PATH ${CMAKE_BINARY_DIR}/include)
file(GLOB HEADER_FILES "*.h")

add_library(tinylist STATIC tinynode.cpp
        tinymanager.cpp)

add_definitions(-D_GLIBCXX_USE_NANOSLEEP)

file(COPY ${HEADER_FILES} DESTINATION ${INCLUDE_PATH})