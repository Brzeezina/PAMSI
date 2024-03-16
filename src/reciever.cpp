#include "reciever.hpp"
#include "sender.hpp"

reciever::reciever(){}

reciever::~reciever(){}

std::string reciever::get_msg(VECTOR::vector_custom &vec){
    std::string msg = "";
    VECTOR::vector_custom rvector(vec.get_size());
    for(size_t i = 0; i < vec.get_size();i++){
        pakiet *pack = (pakiet*)vec[i];
        rvector.add_element(pack->id, (void*)pack);
        // *rvector[pack->id] = (void*)pack;
    }
    for(size_t i = 0; i < rvector.get_size(); i++){
        msg += ((pakiet*)rvector[i])->msg;
    }

    return msg;
}