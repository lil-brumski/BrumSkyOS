cmake_minimum_required(VERSION 3.20.3)

project(BrumSkyOS VERSION 1.0.1 DESCRIPTION "Just for fun, I know it's no way close to being an actual OS.")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(BrumSkyOS SHARED BrumSkyOS-csharp-bindings.cpp ../src/FileManager.cpp ../src/Time.cpp)

set_target_properties(BrumSkyOS PROPERTIES PREFIX "" OUTPUT_NAME "BrumSkyOS")

target_include_directories(BrumSkyOS PUBLIC ../include)