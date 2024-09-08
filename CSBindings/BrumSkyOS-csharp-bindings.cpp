#include <BrumSkyOS/FileManager.hpp>
#include <BrumSkyOS/ErrorHandler.hpp>
#include <BrumSkyOS/Time.hpp>

using namespace BrumSkyOS;

extern "C" void BrumSkyOS_CreateFile(const char* file_name){
  FileManager::CreateFile(file_name);
}

extern "C" void BrumSkyOS_DeleteFile(const char* file_name){
  FileManager::DeleteFile(file_name);
}

extern "C" void BrumSkyOS_RenameFile(const char* file_name,const char* new_name){
  FileManager::RenameFile(file_name, new_name);
}

extern "C" void BrumSkyOS_CreateFolder(const char* folder_name){
  FileManager::CreateFolder(folder_name);
}

extern "C" void BrumSkyOS_DeleteFolder(const char* folder_name){
  FileManager::DeleteFolder(folder_name);
}

extern "C" void BrumSkyOS_RenameFolder(const char* folder_name,const char* new_name){
  FileManager::RenameFolder(folder_name, new_name);
}

extern "C" void BrumSkyOS_WriteToFile(const char* file_name){
  FileManager::WriteToFile(file_name);
}

extern "C" void BrumSkyOS_ReadFile(const char* file_name){
  FileManager::ReadFile(file_name);
}

extern "C" void BrumSkyOS_Time(){
  Time();
}

extern "C" int GetInput(const char* prompt){
  return Input<int>(prompt);
}

