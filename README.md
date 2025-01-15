```This is not an actual Operating System, it's more of a play project to improve on my C++ programming knowledge.```

This project uses C++23.

Necessary stuff to build and run this project:
* 1. C++ 23 compiler (e.g Clang, GNU, etc).
* 2. CMAKE.
* 3. A working command line/terminal.
* 4. Git

To run this project enter these in any directory on your device that you wish to store this repo in. (Installing clang is optional if you want g++ and vice versa): 

Ubuntu/Debian (other OSs are supported too)

```bash
   $ apt install cmake git python g++ libgcc-dev
```

```bash
   $ git clone https://github.com/lil-brumski/BrumSkyOS.git
   $ cd BrumSkyOS/
   $ mkdir build && cd build 
   $ cmake .. && make
   $ ./BrumSkyOS
```

Note: By default, you can only compile statically using GNU Compiler, you can change that. To compile statically, use `cmake -DBRUSTA=ON ..`. Also, it compiles dynamically by default.

What my OS can do:

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

# License

This project uses the MIT License, see below for more info:

[LICENSE](https://github.com/lil-brumski/BrumSkyOS/blob/main/LICENSE)

