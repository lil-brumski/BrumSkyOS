#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

namespace BrumSkyOS{

  class FileManager{
    public:

    static void CreateFile(const std::string& file_name);

    static void DeleteFile(const std::string& file_name);

    static void RenameFile(const std::string& file_name, const std::string& new_name);

    static void CreateFolder(const std::string& folder_name);

    static void DeleteFolder(const std::string& folder_name);

    static void RenameFolder(const std::string& folder_name, const std::string& new_name);

    static void ReadFile(const std::string& file_name);

    static void WriteToFile(const std::string& file_name);

  };
}