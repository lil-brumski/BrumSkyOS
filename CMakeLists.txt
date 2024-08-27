cmake_minimum_required(VERSION 3.20.3)

project(BrumskyOS VERSION 1.0 DESCRIPTION "Just for fun, I know it's no way close to being an actual OS.")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")

add_executable(BrumskyOS ${SOURCES})

target_include_directories(BrumskyOS PRIVATE include)