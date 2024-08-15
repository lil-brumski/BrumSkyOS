#include "error_handler.hpp"
#include "scheduler.hpp"
#include <random>

int main(){
    std::cout << "=======================\n";
    std::cout << "=Welcome to BrumskyOS!=\n";
    std::cout << "=======================\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0,3);
    int hold = 0;
    //ErrorHandler *errorptr;
    
    for(size_t x = 1; x <= 4; x++){
        hold = distribution(gen);
        ErrorHandler *error = new ErrorHandler(hold);
        error->NoError();
        error->Saver();
        error->Crasher();
        delete error;
        error = nullptr;
std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}