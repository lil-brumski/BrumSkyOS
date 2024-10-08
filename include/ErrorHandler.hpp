//Created by David Tamaratare Oghenebrume.
//Copyright (c) 2024 David Tamaratare Oghenebrume
#pragma once

#include <iostream>
#include <sstream>
#include <string>

namespace BrumSkyOS{
  template <class T>
  T Input(const std::string& prompt){
    T value;
    std::string input;
    while (true){
         std::cout << prompt;
         std::getline(std::cin, input);
         std::istringstream stream(input);
         if(stream >> value && stream.eof()){
           break;
         }else{
            std::cerr << "Not a number, try again!\n";
              }
    }
        return value;
  }

}