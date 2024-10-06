//Created by David Tamaratare Oghenebrume.
//Copyright (c) 2024 David Tamaratare Oghenebrume
//Compile using C++23 and above.
#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>
#include <expected>

namespace BrumSkyOS{

  class FileManager{
    public:

    static std::expected<std::string, std::string> CreateFile(const std::string& file_name);

    static std::expected<std::string, std::string> DeleteFile(const std::string& file_name);

    static std::expected<std::string, std::string> RenameFile(const std::string& file_name, const std::string& new_name);

    static std::expected<std::string, std::string> CreateFolder(const std::string& folder_name);

    static std::expected<std::string, std::string> DeleteFolder(const std::string& folder_name);

    static std::expected<std::string, std::string> RenameFolder(const std::string& folder_name, const std::string& new_name);

    static std::expected<std::string, std::string> ReadFile(const std::string& file_name);

    static std::expected<std::string, std::string> WriteToFile(const std::string& file_name);

  };
}