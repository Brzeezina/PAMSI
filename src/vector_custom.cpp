#include "vector_custom.hpp"
#include <stdio.h>
#include <cstdlib>
#include <stdexcept>

using namespace VECTOR;

vector_custom::vector_custom(size_t size_){
    data = (void**)malloc(size_*sizeof(void*));
    size = size_;
}

vector_custom::~vector_custom(){
    free(data);
}

void vector_custom::add_element(size_t index, void* element){
    if(index >= size)
        throw std::invalid_argument("Index is too big");
    data[index] = element;
}

void* vector_custom::operator[](size_t index){
    if(index >= size)
        throw std::invalid_argument("Index is too big");
    
    return data[index];
}

size_t vector_custom::get_size(){
    return size;
}

void vector_custom::swap_elements(size_t index1, size_t index2){
    if(index1 >= size || index2 >= size){
        throw std::invalid_argument("Index out of range");
    }
    void* temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
}