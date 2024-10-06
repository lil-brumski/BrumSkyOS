//I'm too lazy to drop comments on each function Lmao! 🤣 😂
//The function names are self-explanatory though.
//The "FileManager::RenameFile()" function is not 100% efficient! As my C++ knowledge advances, this code will be more efficient, I promise! :)

//Created by David Tamaratare Oghenebrume.
//Copyright (c) 2024 David Tamaratare Oghenebrume
//@lil-brumski on GitHub.
//This project is only meant for improving my C++ knowledge [for now].

#include "FileManager.hpp"

//An alias for the "std::filesystem" namespace.
namespace fs = std::filesystem;

namespace BrumSkyOS{

//This function creates the file when called and given the file name.
std::expected<std::string, std::string> FileManager::CreateFile(const std::string& file_name){
  
  //Creates a variable of type std::filesystem::path that takes in the name of the file.
  fs::path FilePath(file_name);
  
    if(!fs::exists(FilePath)){
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
  fs::path FilePath(file_name);

    if(fs::exists(FilePath)){
        if(fs::remove(FilePath)){
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
  fs::path OldFilePath(file_name);
  fs::path NewFilePath(new_name);
  
    if(fs::exists(OldFilePath) && !fs::exists(NewFilePath)){
        fs::rename(OldFilePath, NewFilePath);
        return "Successfully renamed \'" + file_name + "\' to \'" + new_name + "\'!\n";
    }
    else if(fs::exists(NewFilePath) && fs::exists(OldFilePath)){
        return std::unexpected("Error: \'" + new_name + "\' already exists.");
    }
    else if(!fs::exists(OldFilePath)){
        return std::unexpected("Error: \'" + file_name + "\' does not exist!");
    }
  
  return "";
 
}

std::expected<std::string, std::string> FileManager::CreateFolder(const std::string& folder_name){
  fs::path FolderPath(folder_name);
  
  if(!fs::exists(FolderPath)){
    if(fs::create_directory(FolderPath)){
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
  fs::path FolderPath(folder_name);
  
    if(fs::exists(FolderPath) && fs::is_directory(FolderPath)){
        if(fs::remove(FolderPath)){
          return "Folder deleted successfully!\n";
        }
        else{
          return std::unexpected("Error: Could not delete folder, sorry :(\n");
        }
    }
    else if(!fs::exists(FolderPath)){
         return std::unexpected("Error: Directory does not exist bro :(");
    }
    else{
        return std::unexpected("Error: \'" + folder_name + "\' is a file, not a directory.");
    }
  
  return "";
  
}

std::expected<std::string, std::string> FileManager::RenameFolder(const std::string& folder_name, const std::string& new_name){
  fs::path OldFolderPath(folder_name);
  fs::path NewFolderPath(new_name);
  
    if(fs::exists(OldFolderPath) && fs::is_directory(OldFolderPath)){
        
        if(fs::exists(NewFolderPath) && fs::is_directory(NewFolderPath)){
            return std::unexpected("Error: \'" + new_name + "\' already exists.");
        }
        else if(!fs::is_directory(NewFolderPath)){
            return std::unexpected("Error: \'" + new_name + "\' is a file, you can\'t have a folder have the same name as a file for now, will change in the future.");
        }   
        else{
          fs::rename(OldFolderPath, NewFolderPath);
          return "Successfully renamed \'" + folder_name + "\' to \'" + new_name + "\'!\n";
        }    
           
    }
    else if(!fs::exists(OldFolderPath)){
        return std::unexpected("Error: \'" + folder_name + "\' does not exist!");
    }
    else{
        return std::unexpected("Error: \'" + folder_name + "\' is not a directory!");
    }
  
  return "";
  
}

std::expected<std::string, std::string> FileManager::ReadFile(const std::string& file_name){
  fs::path FilePath(file_name);
 
    if(fs::exists(FilePath)){
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
  fs::path FilePath(file_name);
  
    if(fs::exists(FilePath)){
        std::ofstream File(file_name);
        std::string message = "";
        if(File.is_open()){
          std::print("Enter what you want to have in the file: ");
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