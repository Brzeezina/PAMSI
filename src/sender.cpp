#include "sender.hpp"

using namespace VECTOR;

sender::sender(){}
sender::~sender(){}

vector_custom& sender::send_msg(std::string msg, size_t num_of_bytes){
    size_t num_of_packages = msg.size()/num_of_bytes;
    if(msg.size() - msg.size()/num_of_bytes != 0){
        num_of_packages++;
    }
    vector_custom *vec = new vector_custom(num_of_packages);
 
    //std::cout<<num_of_packages<<std::endl;

    for(size_t i = 0; i < num_of_packages; i++){
        std::string text; //= new std::string;//(std::string*)malloc(sizeof(std::string));
        pakiet *pack = new pakiet();
        if(i != num_of_packages){
            text = msg.substr(i*num_of_bytes,num_of_bytes);
        }else{
            size_t left_bytes = msg.size() - num_of_packages*num_of_bytes;
            text = msg.substr(i*num_of_bytes, left_bytes);
        }
        pack->id = i;
        pack->msg = text;
        vec->add_element(i, (void*)pack);
    }

    srand((unsigned) time(NULL));

    for(size_t i = 0; i < 2*num_of_packages; i++){
        size_t index1 = rand()%num_of_packages;
        size_t index2 = rand()%num_of_packages/2;
        vec->swap_elements(index1, index2);
    }

    return *vec;

    // for(size_t i = 0; i < vec.get_size(); i++){
        // std::cout << *(std::string*)vec[i];
    // }
}
