import build.BrumSkyOS as BrumSkyOS
import sys

print("Welcome to BrumSkyOS, we offer a few services: ")

services = [
   "{1.} Creation of file",
   "{2.} Deletion of file", 
   "{3.} Renaming of file",
   "{4.} Writing to files",
   "{5.} Reading data from files",
   "{6.} Creating folders",
   "{7.} Renaming of folder",
   "{8.} Deletion of folder",
   "{9.} Check current time",
   "{10.} Quit BrumSkyOS"
]

while True:
  print()  
  for s in services:
    print(s)
    
  option = BrumSkyOS.Input("Which would you like to do? [Select the number attached to the activity]: ")
  
  if option == 1:
    UserTask = input("Creating new file, enter file name: ")
    BrumSkyOS.CreateFile(UserTask)
    
  elif option == 2:
    UserTask = input("Deleting file, enter file name: ")
    BrumSkyOS.DeleteFile(UserTask)
    
  elif option == 3:
    UserTask = input("Renaming file, enter old name: ")
    UserTask2 = input("Enter new name: ")
    BrumSkyOS.RenameFile(UserTask, UserTask2)
    
  elif option == 4:
    UserTask = input("Enter the file name: ")
    BrumSkyOS.WriteToFile(UserTask)
    
  elif option == 5:
    UserTask = input("Enter the file name: ")
    BrumSkyOS.ReadFile(UserTask)
    
  elif option == 6:
    UserTask = input( "Creating new folder, enter folder name: ")
    BrumSkyOS.CreateFolder(UserTask)
    
  elif option == 7:
    UserTask = input("Renaming folder, enter old name: ")
    UserTask2 = input("Enter new name: ")
    BrumSkyOS.RenameFolder(UserTask, UserTask2)
    
  elif option == 8:
    UserTask = input("Deleting folder, enter folder name: ")
    BrumSkyOS.DeleteFolder(UserTask)
   
  elif option == 9:
    print("The current time is: ");
    BrumSkyOS.Time()

  elif option == 10:
    print("Good bye!")
    sys.exit(0)
    
  else:
    print("Invalid option!")