#include "FileManager.hpp"
#include "ErrorHandler.hpp"
#include <memory>

int main(){
  
  std::cout << "Welcome to BrumSkyOS, we offer a few services: ";
  std::string UserTask = "";
        
  std::string services = "{1.} Creation of file {2.} Deletion of file {3.} Renaming of file {4.} Writing to files {5.} Reading data from files {6.} Creating folders {7.} Renaming of folder {8.} Deletion of folder  {9.} Quit BrumSkyOS\n";
  
while(true){     
    std::cout << services;
      
    auto OptionPtr = std::make_unique<int>(Input<int>("Which would you like to do? [Select the number attached to the activity]: "));
    
    switch(*OptionPtr){
        case 1:
          std::cout << "Enter file name: ";
          getline(std::cin, UserTask);
          FileManager::CreateFile(UserTask);
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          break;
        case 8:
          break;
        case 9:
          break;
        default:
          std::cout << "Invalid option!\n";
    }

     
  }
  
  
  

}