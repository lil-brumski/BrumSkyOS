//This is the main file if this project.
//Made by David Tamaratare Oghenebrume. 
//@lil-brumski on GitHub.
//This project is only meant for improving my C++ knowledge [for now].

#include <BrumSkyOS/FileManager.hpp>
#include <BrumSkyOS/ErrorHandler.hpp>
#include <BrumSkyOS/Time.hpp>
#include <array>

int main(){
  
  std::cout << "Welcome to BrumSkyOS, we offer a few services: ";
  std::string UserTask = "";
  std::string UserTask2 = "";
  int Option = 0;
  
  //This is a type of C++ array that uses the principle of Resource Acquisition Is Initialisation [R.A.I.I.].. It stores 10 string elements.
  std::array<std::string, 10> services = 
  {
   "{1.} Creation of file",
   "{2.} Deletion of file", 
   "{3.} Renaming of file",
   "{4.} Writing to files",
   "{5.} Reading data from files",
   "{6.} Creating folders",
   "{7.} Renaming of folder",
   "{8.} Deletion of folder",
   "{9.} Current Time",
   "{10.} Quit BrumSkyOS"
   };
  


while(true){  
    std::cout << std::endl;
     
     //A for-loop that prints out each element of the "services" array.
    for(auto& s: services){
        std::cout << s << std::endl;
    }
    
    //The "BrumSkyOS::Input<>() is a function that makes sure the data type in the '<>' is the one entered." 
    Option = BrumSkyOS::Input<int>("Which would you like to do? [Select the number attached to the activity]: ");
    
    std::cout << std::endl;
    
    //This is an alternative to if-else statements.
    switch(Option){
        case 1:
          std::cout << "Creating new file, enter file name: ";
          getline(std::cin, UserTask);
          BrumSkyOS::FileManager::CreateFile(UserTask);
          break;
          
        case 2:
          std::cout << "Deleting file, enter file name: ";
          getline(std::cin, UserTask);
          BrumSkyOS::FileManager::DeleteFile(UserTask);
          break;
          
        case 3:
          std::cout << "Renaming file, enter old name: ";
          getline(std::cin, UserTask);
          std::cout << "Enter new name: ";
          getline(std::cin, UserTask2);
          BrumSkyOS::FileManager::RenameFile(UserTask, UserTask2);
          break;
          
        case 4:
          std::cout << "Enter the file name: ";
          getline(std::cin, UserTask);
          BrumSkyOS::FileManager::WriteToFile(UserTask);
          break;
          
        case 5:
          std::cout << "Enter the file name: ";
          getline(std::cin, UserTask);
          BrumSkyOS::FileManager::ReadFile(UserTask);
          break;
          
        case 6:
          std::cout << "Creating new folder, enter folder name: ";
          getline(std::cin, UserTask);
          BrumSkyOS::FileManager::CreateFolder(UserTask);
          break;
          
        case 7:
          std::cout << "Renaming folder, enter old name: ";
          getline(std::cin, UserTask);
          std::cout << "Enter new name: ";
          getline(std::cin, UserTask2);
          BrumSkyOS::FileManager::RenameFolder(UserTask, UserTask2);
          break;
          
        case 8:
          std::cout << "Deleting folder, enter folder name: ";
          getline(std::cin, UserTask);
          BrumSkyOS::FileManager::DeleteFolder(UserTask);
          break;
   
        case 9:
          std::cout << "The current time is: ";
          BrumSkyOS::Time();
          break;
        
        //If the user enters "10" the program will end. 
        case 10:
          std::cout << "Good bye!\n";
          return 0;
          break;
          
        default:
          std::cout << "Invalid option!\n";
    }

     
  }
  

}