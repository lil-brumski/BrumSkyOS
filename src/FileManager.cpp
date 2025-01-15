/*
MIT License 

Copyright (c) 2024 David Tamaratare Oghenebrume

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "FileManager.hpp"

namespace BrumSkyOS{

//This function creates the file when called and given the file name.
std::expected<std::string, std::string> FileManager::CreateFile(const std::string& file_name){
  
  //Creates a variable of type std::filesystem::path that takes in the name of the file.
  std::filesystem::path FilePath(file_name);
  
    if(!std::filesystem::exists(FilePath)){
        //The "std::ofstream" class is useful when you want to create or write to a file. "File" is the object.
        std::ofstream File(file_name);
        //Checks if the file is open [it's kinda self-explanatory but comments are important, lmao]
        if(File.is_open()){
          return "\'" + file_name + "\' successfully created!\n";
          File.close();
        }
        else{
          return std::unexpected("An error occurred!\n");
        }
    }
    else{
        return std::unexpected("Error: File already exists!");
    }
  
  return "";
  
}

std::expected<std::string, std::string> FileManager::DeleteFile(const std::string& file_name){
  std::filesystem::path FilePath(file_name);

    if(std::filesystem::exists(FilePath)){
        if(std::filesystem::remove(FilePath)){
          return "\'" + file_name + "\' successfully deleted!\n";
        }
        else{
          return std::unexpected("Error: Couldn\'t delete file, try again.\n");
        }
    }
    else{
       return std::unexpected("Error: File does not exist in the first place!");
    }
  
  return "";
  
}

std::expected<std::string, std::string> FileManager::RenameFile(const std::string& file_name, const std::string& new_name){
  std::filesystem::path OldFilePath(file_name);
  std::filesystem::path NewFilePath(new_name);
  
    if(std::filesystem::exists(OldFilePath) && !std::filesystem::exists(NewFilePath)){
        std::filesystem::rename(OldFilePath, NewFilePath);
        return "Successfully renamed \'" + file_name + "\' to \'" + new_name + "\'!\n";
    }
    else if(std::filesystem::exists(NewFilePath) && std::filesystem::exists(OldFilePath)){
        return std::unexpected("Error: \'" + new_name + "\' already exists.");
    }
    else if(!std::filesystem::exists(OldFilePath)){
        return std::unexpected("Error: \'" + file_name + "\' does not exist!");
    }
  
  return "";
 
}

std::expected<std::string, std::string> FileManager::CreateFolder(const std::string& folder_name){
  std::filesystem::path FolderPath(folder_name);
  
  if(!std::filesystem::exists(FolderPath)){
    if(std::filesystem::create_directory(FolderPath)){
          return "Folder created successfully!\n";
        }
        else{
          return std::unexpected("Error: Could not create folder, try again.\n");
        }
    }
    else{
        return std::unexpected("Error: Folder already exists!");
    }
  
  return "";
  
}

std::expected<std::string, std::string> FileManager::DeleteFolder(const std::string& folder_name){
  std::filesystem::path FolderPath(folder_name);
  
    if(std::filesystem::exists(FolderPath) && std::filesystem::is_directory(FolderPath)){
        if(std::filesystem::remove(FolderPath)){
          return "Folder deleted successfully!\n";
        }
        else{
          return std::unexpected("Error: Could not delete folder, sorry :(\n");
        }
    }
    else if(!std::filesystem::exists(FolderPath)){
         return std::unexpected("Error: Directory does not exist bro :(");
    }
    else{
        return std::unexpected("Error: \'" + folder_name + "\' is a file, not a directory.");
    }
  
  return "";
  
}

std::expected<std::string, std::string> FileManager::RenameFolder(const std::string& folder_name, const std::string& new_name){
  std::filesystem::path OldFolderPath(folder_name);
  std::filesystem::path NewFolderPath(new_name);
  
    if(std::filesystem::exists(OldFolderPath) && std::filesystem::is_directory(OldFolderPath)){
        
        if(std::filesystem::exists(NewFolderPath) && std::filesystem::is_directory(NewFolderPath)){
            return std::unexpected("Error: \'" + new_name + "\' already exists.");
        }
        else if(!std::filesystem::is_directory(NewFolderPath)){
            return std::unexpected("Error: \'" + new_name + "\' is a file, you can\'t have a folder have the same name as a file for now, will change in the future.");
        }   
        else{
          std::filesystem::rename(OldFolderPath, NewFolderPath);
          return "Successfully renamed \'" + folder_name + "\' to \'" + new_name + "\'!\n";
        }    
           
    }
    else if(!std::filesystem::exists(OldFolderPath)){
        return std::unexpected("Error: \'" + folder_name + "\' does not exist!");
    }
    else{
        return std::unexpected("Error: \'" + folder_name + "\' is not a directory!");
    }
  
  return "";
  
}

std::expected<std::string, std::string> FileManager::ReadFile(const std::string& file_name){
  std::filesystem::path FilePath(file_name);
 
    if(std::filesystem::exists(FilePath)){
        std::ifstream File(file_name);
        std::string line = "";
        while(std::getline(File, line)){
          std::cout << line << std::endl;
        }
        File.close();
        return "Successfully read through file!\n";
     }
     else{
         return std::unexpected("Error: File does not exist, create the file first.");
     }
  
  return "";
  
}

std::expected<std::string, std::string> FileManager::WriteToFile(const std::string& file_name){
  std::filesystem::path FilePath(file_name);
  
    if(std::filesystem::exists(FilePath)){
        std::ofstream File(file_name);
        std::string message = "";
        if(File.is_open()){
          std::cout << "Enter what you want to have in the file: ";
          std::getline(std::cin, message);
          File << message << std::endl;
          File.close();
          return "Successfully written to file!\n";
        }
        else{
          return std::unexpected("Error: Could not open file, try again.\n");
        }
    }
    else{
        return std::unexpected("Error: Create file first before attempting to write to it!");
    }
  
  return "";
  
}


}