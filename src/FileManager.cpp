#include <FileManager.hpp>

namespace fs = std::filesystem;

namespace BrumSkyOS{


void FileManager::CreateFile(const std::string& file_name){
  fs::path FilePath(file_name);
  
  try{
    if(!fs::exists(FilePath)){
        std::ofstream File(file_name);
        if(File.is_open()){
          std::cout << "\'" << file_name << "\' successfully created!\n";
          File.close();
        }
        else{
          std::cout << "An error occurred!\n";
        }
    }
    else{
        throw std::runtime_error("File already exists!");
    }
  }
  catch(const std::exception& error){
      std::cerr << "Error: " << error.what() << std::endl;
  }
}

void FileManager::DeleteFile(const std::string& file_name){
  fs::path FilePath(file_name);

  try{
    if(fs::exists(FilePath)){
        if(fs::remove(FilePath)){
          std::cout << "\'" << file_name << "\' successfully deleted!\n";
        }
        else{
          std::cout << "Couldn\'t delete file, try again.\n";
        }
    }
    else{
      throw std::runtime_error("File does not exist in the first place!");
    }
  }
  catch(const std::exception& error){
      std::cerr << "Error: " << error.what() << std::endl;
  }

}

void FileManager::RenameFile(const std::string& file_name, const std::string& new_name){
  fs::path OldFilePath(file_name);
  fs::path NewFilePath(new_name);
  
  try{
    if(fs::exists(OldFilePath) && !fs::exists(NewFilePath)){
        fs::rename(OldFilePath, NewFilePath);
        std::cout << "Successfully renamed \'" << file_name << "\' to \'" << new_name << "\'!\n";
    }
    else{
        throw std::runtime_error("\'" + file_name + "\' does not exist!");
    }
  }
  catch(const std::exception& error){
      std::cerr << "Error: " << error.what() << std::endl;
  }
}

void FileManager::CreateFolder(const std::string& folder_name){
  fs::path FolderPath(folder_name);
  
  try{
    if(!fs::exists(FolderPath)){
        if(fs::create_directory(FolderPath)){
          std::cout << "Folder created successfully!\n";
        }
        else{
          std::cout << "Could not create folder, try again.\n";
        }
    }
    else{
        throw std::runtime_error("Folder already exists!");
    }
  }
  catch(const std::exception& error){
      std::cerr << "Error: " << error.what() << std::endl;
  }
}

void FileManager::DeleteFolder(const std::string& folder_name){
  fs::path FolderPath(folder_name);
  
  try{
    if(fs::exists(FolderPath)){
        if(fs::remove(FolderPath)){
          std::cout << "Folder deleted successfully!\n";
        }
        else{
          std::cout << "Could not delete folder, sorry :(\n";
        }
    }
    else{
        throw std::runtime_error("Directory does not exist bro :(");
    }
  }
  catch(const std::exception& error){
      std::cerr << "Error: " << error.what() << std::endl;
  }
}

void FileManager::RenameFolder(const std::string& folder_name, const std::string& new_name){
  fs::path OldFolderPath(folder_name);
  fs::path NewFolderPath(new_name);
  
  try{
    if(fs::exists(OldFolderPath) && !fs::exists(NewFolderPath)){
        fs::rename(OldFolderPath, NewFolderPath);
        std::cout << "Successfully renamed \'" << folder_name << "\' to \'" << new_name << "\'!\n";
    }
    else{
        throw std::runtime_error("\'" + folder_name + "\' does not exist!");
    }
  }
  catch(const std::exception& error){
      std::cerr << "Error: " << error.what() << std::endl;
  }
}

void FileManager::ReadFile(const std::string& file_name){
  fs::path FilePath(file_name);
  
  try{
    if(fs::exists(FilePath)){
        std::ifstream File(file_name);
        std::string line = "";
        while(std::getline(File, line)){
          std::cout << line << std::endl;
        }
        File.close();
     }
     else{
         throw std::runtime_error("File does not exist, create the file first.");
     }
  }
  catch(const std::exception& error){
      std::cerr << "Error: " << error.what() << std::endl;
  }
}

void FileManager::WriteToFile(const std::string& file_name){
  fs::path FilePath(file_name);
  
  try{
    if(fs::exists(FilePath)){
        std::ofstream File(file_name);
        std::string message = "";
        if(File.is_open()){
          std::cout << "Enter what you want to have in the file: ";
          std::getline(std::cin, message);
          File << message << std::endl;
          File.close();
        }
        else{
          std::cout << "Could not open file, try again.\n";
        }
    }
    else{
        throw std::runtime_error("Create file before attempting to write to it!");
    }
  }
  catch(const std::exception& error){
      std::cerr << "Error: " << error.what() << std::endl;
  }
}


}