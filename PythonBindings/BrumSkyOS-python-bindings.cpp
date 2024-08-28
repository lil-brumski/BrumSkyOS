#include "FileManager.hpp"
#include "ErrorHandler.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(BrumSkyOS, b){
    b.doc() = "Just for fun, I know it's no way close to being an actual OS.";

    b.def("CreateFile", &FileManager::CreateFile, "A function for creating files.");
    
    b.def("DeleteFile", &FileManager::DeleteFile, "A function for deleting files.");
    
    b.def("RenameFile", &FileManager::RenameFile, "A function for renaming files.");
    
    b.def("CreateFolder", &FileManager::CreateFolder, "A function for creating folders.");
    
    b.def("DeleteFolder", &FileManager::DeleteFolder, "A function for deleting files.");
    
    b.def("RenameFolder", &FileManager::RenameFolder, "A function for renaming files.");
    
    b.def("ReadFile", &FileManager::ReadFile, "A function for reading contents of files.");
    
    b.def("WriteToFile", &FileManager::WriteToFile, "A function for writing to files.");
    
    b.def("Input", &Input<int>, "A function that makes sure the user enters an integer.");
    
 
}