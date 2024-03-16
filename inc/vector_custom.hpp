#include <stdio.h>
#include <string.h>
#ifndef VECTOR_CUSTOM_HPP
#define VECTOR_CUSTOM_HPP

namespace VECTOR{
    class vector_custom
    {
    private:
        void ** data;
        size_t size;
    public:
        vector_custom(size_t size);
        ~vector_custom();
        void add_element(size_t index, void* element);
        void* operator[](size_t index);
        size_t get_size();
        void swap_elements(size_t index1, size_t index2);
    };
}
#endif
