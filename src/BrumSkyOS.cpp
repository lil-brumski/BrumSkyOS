/*
MIT License 

Copyright (c) 2024 David Tamaratare Oghenebrume

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <FileManager.hpp>
#include <ErrorHandler.hpp>
#include <Time.hpp>
#include <array>

int main(){
  
  std::cout << "Welcome to BrumSkyOS, we offer a few services: ";
  std::string UserTask = "";
  std::string UserTask2 = "";
  int Option = 0;
  
  //This is a type of C++ array that uses the principle of Resource Acquisition Is Initialisation [R.A.I.I.].. It stores 10 string elements. :)
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
  
   std::expected<std::string, std::string> result;

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
          result = BrumSkyOS::FileManager::CreateFile(UserTask);
          if(!result){
           std::cout << result.error() << std::endl;
          }
          else{
           std::cout << result.value();
          }
          break;
          
        case 2:
          std::cout << "Deleting file, enter file name: ";
          getline(std::cin, UserTask);
          result = BrumSkyOS::FileManager::DeleteFile(UserTask);
          if(!result){
           std::cout << result.error() << std::endl;
          }
          else{
           std::cout << result.value();
          }
          break;
          
        case 3:
          std::cout << "Renaming file, enter old name: ";
          getline(std::cin, UserTask);
          std::cout << "Enter new name: ";
          getline(std::cin, UserTask2);
          result = BrumSkyOS::FileManager::RenameFile(UserTask, UserTask2);
          if(!result){
           std::cout << result.error() << std::endl;
          }
          else{
           std::cout << result.value();
          }
          break;
          
        case 4:
          std::cout << "Enter the file name: ";
          getline(std::cin, UserTask);
          result = BrumSkyOS::FileManager::WriteToFile(UserTask);
          if(!result){
           std::cout << result.error() << std::endl;
          }    
          else{
           std::cout << result.value();
          }
          break;
          
        case 5:
          std::cout << "Enter the file name: ";
          getline(std::cin, UserTask);
          result = BrumSkyOS::FileManager::ReadFile(UserTask);
          if(!result){
           std::cout << result.error() << std::endl;
          }  
          else{
           std::cout << result.value();
          }
          break;
          
        case 6:
          std::cout << "Creating new folder, enter folder name: ";
          getline(std::cin, UserTask);
          result = BrumSkyOS::FileManager::CreateFolder(UserTask);
          if(!result){
           std::cout << result.error() << std::endl;
          }
          else{
           std::cout << result.value();
          }
          break;
          
        case 7:
          std::cout << "Renaming folder, enter old name: ";
          getline(std::cin, UserTask);
          std::cout << "Enter new name: ";
          getline(std::cin, UserTask2);
          result = BrumSkyOS::FileManager::RenameFolder(UserTask, UserTask2);
          if(!result){
           std::cout << result.error() << std::endl;
          }
          else{
           std::cout << result.value();
          }
          break;
          
        case 8:
          std::cout << "Deleting folder, enter folder name: ";
          getline(std::cin, UserTask);
          result = BrumSkyOS::FileManager::DeleteFolder(UserTask);
          if(!result){
           std::cout << result.error() << std::endl;
          }
          else{
           std::cout << result.value();
          }
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