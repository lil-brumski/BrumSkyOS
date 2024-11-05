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
    set(BUILD_SHARED_LIBS OFF)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
else()
    message(STATUS "Configuring for unknown compiler.")
endif()

file(GLOB SOURCES "src/*.cpp")

add_executable(BrumSkyOS ${SOURCES})

target_include_directories(BrumSkyOS PRIVATE include)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(BrumSkyOS
        -static-libgcc 
        -static-libstdc++
    )
endif()
