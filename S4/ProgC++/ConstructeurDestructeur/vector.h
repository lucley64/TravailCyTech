#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>


namespace my {
    class vector {
        int* elements;
        size_t size{};
    public:
        explicit vector(size_t size);
        [[nodiscard]] size_t get_size() const;
        int& operator[](unsigned long i) const;
    };
}




#endif //VECTOR_H
