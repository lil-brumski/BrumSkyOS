```This is not an actual Operating System, it's more of a play project to improve on my C++ programming knowledge.```

Update: This project now has Python/C++ and C++/C# bindings. You also have to build this project from scratch to use it.

Necessary stuff to run this project:
* 1. C++ compiler (e.g Clang, GNU, etc).
* 2. CMAKE.
* 3. A working command line/terminal.
* 4. Download `git` on your device's terminal.
* 5. Download ```python```
* 6. Download a C# compiler e.g ```mono```
* In summary, run ```$ pkg install clang cmake git python mono```

To run this project: 

1. Run this in any directory on your device that you wish to store this repo in: ```$ git clone https://github.com/lil-brumski/BrumSkyOS.git```

2. Run this: ```$ cd BrumSkyOS/```

3. Run these codes: ```$ mkdir build && cd build/```

4. Compile the project using cmake and make: ```$ cmake .. && make```

5. Run the executable: ```$ ./BrumSkyOS```

6. For the python version, from the ```$ BrumSkyOS/``` directory, run ```$ cd PythonBindings/```

7.  Download [pybind11](https://github.com/pybind/pybind11) from its GitHub repo into the ```PythonBindings/``` folder by running ```$ git clone https://github.com/pybind/pybind11.git``` and then ```$ mkdir build && cd build/```

8. Run ```$ cmake .. && make```

9. Give the executable execution permissions and go back one directory.

10. Run ```$ python BrumSkyOS.py```

11. For the C# version, from the ```$ BrumSkyOS/``` directory, run ```$ cd CSBindings/```

12. Run ```$ mkdir build && cd build/```

13. Then run ```$ cmake .. && make```

14. Run ```cd ..``` and compile the C# code and run it e.g ```$ csc BrumSkyOS.cs && mono BrumSkyOS.exe```

What my 'OS' can do:

* 1. Creation of files.
* 2. Deletion of files.
* 3. Renaming of files.
* 4. Writing to files.
* 5. Reading data from files.
* 6. Creating folders.
* 7. Renaming of folders.
* 8. Deletion of folders.
* 9. Checking of current time.

___Made by David Tamaratare Oghenebrume, a Computer Engineering student of *Rivers State University*, Port Harcourt, Nigeria.___

## Acknowledgements

This project uses [Pybind11](https://github.com/pybind/pybind11).

**Copyright Notice**:

Copyright (c) 2016 Wenzel Jakob wenzel.jakob@epfl.ch, All rights reserved.
