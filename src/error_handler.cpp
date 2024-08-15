#include "error_handler.hpp"

void ErrorHandler::NoError(){
    if(number == 2){
       std::cout << "No worries!\n";
    }
    else if(number == 3){
       std::cout << "No worries!\n";
    }
std::this_thread::sleep_for(std::chrono::seconds(1));
}
void ErrorHandler::Saver(){
    try{
        if(number == 1){
            throw std::runtime_error("System about to crash...");
        }
    }
    catch(const std::exception& warning){
        std::cerr << "Warning: " << warning.what() << std::endl;
std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void ErrorHandler::Crasher(){
    if(number == 0){
      std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "System crashed, now back online!\n";
    }
}