#pragma once

#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>

class ErrorHandler{
public:
  ErrorHandler(int& number){
    this->number = number;
}
  void NoError();
  void Saver();
  void Crasher();
private:
  int number = 0;
};