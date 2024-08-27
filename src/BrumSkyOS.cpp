#include "FileManager.hpp"
#include "ErrorHandler.hpp"
#include <memory>
#include <array>

int main(){
  
  std::cout << "Welcome to BrumSkyOS, we offer a few services: ";
  std::string UserTask = "";
  std::string UserTask2 = "";
        
  std::array<std::string, 9> services = 
  {
   "{1.} Creation of file",
   "{2.} Deletion of file", 
   "{3.} Renaming of file",
   "{4.} Writing to files",
   "{5.} Reading data from files",
   "{6.} Creating folders",
   "{7.} Renaming of folder",
   "{8.} Deletion of folder",
   "{9.} Quit BrumSkyOS"
   };
  
while(true){  
    std::cout << std::endl;
      
    for(auto& s: services){
        std::cout << s << std::endl;
    }
      
    auto OptionPtr = std::make_unique<int>(Input<int>("Which would you like to do? [Select the number attached to the activity]: "));
    
    std::cout << std::endl;
    
    switch(*OptionPtr){
        case 1:
          std::cout << "Creating new file, enter file name: ";
          getline(std::cin, UserTask);
          FileManager::CreateFile(UserTask);
          break;
          
        case 2:
          std::cout << "Deleting file, enter file name: ";
          getline(std::cin, UserTask);
          FileManager::DeleteFile(UserTask);
          break;
          
        case 3:
          std::cout << "Renaming file, enter old name: ";
          getline(std::cin, UserTask);
          std::cout << "Enter new name: ";
          getline(std::cin, UserTask2);
          FileManager::RenameFile(UserTask, UserTask2);
          break;
          
        case 4:
          std::cout << "Enter the file name: ";
          getline(std::cin, UserTask);
          FileManager::WriteToFile(UserTask);
          break;
          
        case 5:
          std::cout << "Enter the file name: ";
          getline(std::cin, UserTask);
          FileManager::ReadFile(UserTask);
          break;
          
        case 6:
          std::cout << "Creating new folder, enter folder name: ";
          getline(std::cin, UserTask);
          FileManager::CreateFolder(UserTask);
          break;
          
        case 7:
          std::cout << "Renaming folder, enter old name: ";
          getline(std::cin, UserTask);
          std::cout << "Enter new name: ";
          getline(std::cin, UserTask2);
          FileManager::RenameFolder(UserTask, UserTask2);
          break;
          
        case 8:
          std::cout << "Deleting folder, enter folder name: ";
          getline(std::cin, UserTask);
          FileManager::DeleteFolder(UserTask);
          break;
          
        case 9:
          std::cout << "Good bye!\n";
          return 0;
          break;
          
        default:
          std::cout << "Invalid option!\n";
    }

     
  }
  
  std::cout << "Ratio";
  

}