#include <iostream>
#include "vector_custom.hpp"
#include <string>

typedef struct{
    std::string msg;
    size_t id;
}pakiet;

class sender
{
public:
    sender();
    ~sender();
    VECTOR::vector_custom& send_msg(std::string msg, size_t num_of_bytes);
};