#include "Time.hpp"

namespace BrumSkyOS{
  //This void function prints out the current time.
  void Time(){
    //Don't really understand the process, but hey it works!
    auto now = std::chrono::system_clock::now();
      
    auto time_now = std::chrono::system_clock::to_time_t(now);
      
    std::cout << std::ctime(&time_now) << std::endl;
  }
}    
