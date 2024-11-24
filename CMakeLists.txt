cmake_minimum_required(VERSION 3.20.3)

project(BrumSkyOS VERSION 1.0.2 DESCRIPTION "Just for fun, I know it's no way close to being an actual OS.")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(ANDROID)
   message(STATUS "==========Building for Android platform==========")
elseif(WIN32)
   message(STATUS "=========Building for Windows platform==========")
elseif(UNIX)
   if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
      message(STATUS "==========Building for Linux==========")
   elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
      message(STATUS "==========Building for MacOS==========")
   else()
      message(STATUS "==========Building for Unknown UNIX platform==========") 
    endif()
else()
     message(STATUS "==========Building for unknown platform==========")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "==========Configuring for Clang==========")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "==========Configuring for GNU==========")
else()
    message(STATUS "Configuring for unknown compiler.")
endif()

add_executable(BrumSkyOS src/BrumSkyOS.cpp
                         src/FileManager.cpp
                         src/Time.cpp
               )

target_include_directories(BrumSkyOS PRIVATE include)

option(BRUSTA "To build the library statically with GNU Compiler" OFF)

if(BRUSTA)
   if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
       message(STATUS "==========Compiling for GNU statically==========")
       target_link_options(BrumSkyOS PRIVATE -static-libgcc -static-libstdc++)
   else()
       message(FATAL_ERROR "==========Error, current compiler isn't GNU!==========")
   endif()
endif()
