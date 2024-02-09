#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>


namespace my {
    class vector {
        int* elements;
        size_t size{};
    public:
        explicit vector(size_t size);
        vector(const vector& v);
        [[nodiscard]] size_t get_size() const;
        int& operator[](unsigned long i) const;

        vector& operator = (const vector& v);

        ~vector() = default;
    };
}




#endif //VECTOR_H
