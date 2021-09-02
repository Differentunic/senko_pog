cmake_minimum_required(VERSION 3.20)
project(senko_pog)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(include ${GTKMM_INCLUDE_DIRS})

set(SOURCE_FILES pog.c main.cpp)

add_executable(senko_pog ${SOURCE_FILES})

target_link_libraries(senko_pog ${GTKMM_LIBRARIES})
