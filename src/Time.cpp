#include <Time.hpp>

namespace BrumSkyOS{
  void Time(){
    auto now = std::chrono::system_clock::now();
      
    auto time_now = std::chrono::system_clock::to_time_t(now);
      
    std::cout << std::ctime(&time_now) << std::endl;
  }
}    
