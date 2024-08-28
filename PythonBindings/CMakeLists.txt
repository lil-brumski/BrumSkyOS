cmake_minimum_required(VERSION 3.20.3)

project(BrumSkyOS VERSION 1.0 DESCRIPTION "Just for fun, I know it's no way close to being an actual OS.")

# Find pybind11 installed in the system
add_subdirectory(pybind11)

# Find Python3 interpreter and development files
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create Python module
pybind11_add_module(BrumSkyOS BrumSkyOS-python-bindings.cpp ../src/FileManager.cpp)

target_include_directories(BrumSkyOS PRIVATE ../include)

# Link the Python libraries
target_link_libraries(BrumSkyOS PRIVATE Python3::Python)

# Set target properties
set_target_properties(BrumSkyOS PROPERTIES COMPILE_FLAGS "-O0")
