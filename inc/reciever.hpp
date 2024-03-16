#include <iostream>
#include "vector_custom.hpp"

class reciever
{
public:
    reciever();
    ~reciever();
    std::string get_msg(VECTOR::vector_custom &vec);
};
