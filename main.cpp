#include <chrono>
#include <iostream>
#include "file_opener.hpp"
#include "sender.hpp"
#include "vector_custom.hpp"
#include "reciever.hpp"

int main(){
    
    file_opener message("../biblia.txt");
    sender sender;
    VECTOR::vector_custom& vec = sender.send_msg(message.read_file(), 1);
    reciever reciever;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    reciever.get_msg(vec);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    auto elapsed_seconds = std::chrono::duration<double, std::milli>(end - begin).count();
    std::cout<< "Czas wykonania: " << elapsed_seconds << "ms\n";
    
    //printf("%d", elapsed_seconds);

    return 0;
} 