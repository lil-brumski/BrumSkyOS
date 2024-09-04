using System;
using System.Linq;
using System.Runtime.InteropServices;

//namespace HelloWold;

public static class Program
{
    [DllImport("build/BrumSkyOS.so", CallingConvention = CallingConvention.Cdecl)]
    public static extern void BrumSkyOS_CreateFile(string file_name);

    [DllImport("build/BrumSkyOS.so", CallingConvention = CallingConvention.Cdecl)]
    public static extern void BrumSkyOS_DeleteFile(string file_name);

    [DllImport("build/BrumSkyOS.so", CallingConvention = CallingConvention.Cdecl)]
    public static extern void BrumSkyOS_RenameFile(string file_name, string new_name);

    [DllImport("build/BrumSkyOS.so", CallingConvention = CallingConvention.Cdecl)]
    public static extern void BrumSkyOS_CreateFolder(string folder_name);

    [DllImport("build/BrumSkyOS.so", CallingConvention = CallingConvention.Cdecl)]
    public static extern void BrumSkyOS_DeleteFolder(string folder_name);

    [DllImport("build/BrumSkyOS.so", CallingConvention = CallingConvention.Cdecl)]
    public static extern void BrumSkyOS_RenameFolder(string folder_name, string new_name);

    [DllImport("build/BrumSkyOS.so", CallingConvention = CallingConvention.Cdecl)]
    public static extern void BrumSkyOS_WriteToFile(string file_name);

    [DllImport("build/BrumSkyOS.so", CallingConvention = CallingConvention.Cdecl)]
    public static extern void BrumSkyOS_ReadFile(string file_name);

    [DllImport("build/BrumSkyOS.so", CallingConvention = CallingConvention.Cdecl)]
    public static extern void BrumSkyOS_Time();

    [DllImport("build/BrumSkyOS.so", CallingConvention = CallingConvention.Cdecl)]
    public static extern int GetInput(string prompt);

    public static void Main()
    {

        Console.WriteLine("Welcome to BrumSkyOS, we offer a few services: ");
        string UserTask = "";
        string UserTask2 = "";

        int Option = 0;

        string[] services = new string[10] {
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

        while (true)
        {
            Console.WriteLine();

            for (int x = 0; x < services.Length; x++)
            {
                Console.WriteLine(services[x]);
            }

            Option = GetInput("Which would you like to do? [Select the number attached to the activity]: ");

            Console.WriteLine();

            switch (Option)
            {
                case 1:
                    Console.Write("Creating new file, enter file name: ");
                    UserTask = Console.ReadLine();
                    BrumSkyOS_CreateFile(UserTask);
                    break;

                case 2:
                    Console.Write("Deleting file, enter file name: ");
                    UserTask = Console.ReadLine();
                    BrumSkyOS_DeleteFile(UserTask);
                    break;

                case 3:
                    Console.Write("Renaming file, enter old name: ");
                    UserTask = Console.ReadLine();
                    Console.Write("Enter new name: ");
                    UserTask2 = Console.ReadLine();
                    BrumSkyOS_RenameFile(UserTask, UserTask2);
                    break;

                case 4:
                    Console.Write("Enter the file name: ");
                    UserTask = Console.ReadLine();
                    BrumSkyOS_WriteToFile(UserTask);
                    break;

                case 5:
                    Console.Write("Enter the file name: ");
                    UserTask = Console.ReadLine();
                    BrumSkyOS_ReadFile(UserTask);
                    break;

                case 6:
                    Console.Write("Creating new folder, enter folder name: ");
                    UserTask = Console.ReadLine();
                    BrumSkyOS_CreateFolder(UserTask);
                    break;

                case 7:
                    Console.Write("Renaming folder, enter old name: ");
                    UserTask = Console.ReadLine();
                    Console.Write("Enter new name: ");
                    UserTask2 = Console.ReadLine();
                    BrumSkyOS_RenameFolder(UserTask, UserTask2);
                    break;

                case 8:
                    Console.Write("Deleting folder, enter folder name: ");
                    UserTask = Console.ReadLine();
                    BrumSkyOS_DeleteFolder(UserTask);
                    break;

                case 9:
                    Console.Write("The current time is: ");
                    BrumSkyOS_Time();
                    break;

                case 10:
                    Console.Write("Good bye!\n");
                    Environment.Exit(0);
                    break;

                default:
                    Console.Write("Invalid option!\n");
                    break;
            }


        }

    }
}

