//
// Created by cytech on 27/03/24.
//

#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include <iostream>
#include <sstream>



namespace my {
    template<typename T>
    class vector {
        T* _elem;
        std::size_t _size{};

    public:
        explicit vector(const std::size_t size): _size(size) {
            _elem = static_cast<T *>(malloc(_size * sizeof(T)));
        }

        ~vector() {
            free(_elem);
        }

        T& operator[](std::size_t i) {
            if (i >= _size) {
                std::stringstream ss;
                ss << "Index " << i << " is out of range.";
                throw std::out_of_range(ss.str());
            }
            return _elem[i];
        }

        const T& operator[](size_t i) const {
            if (i >= _size) {
                std::stringstream ss;
                ss << "Index " << i << " is out of range.";
                throw std::out_of_range(ss.str());
            }
            return _elem[i];
        }

        [[nodiscard]] std::size_t size() const {
            return _size;
        }

        T* begin() {
            return _elem;
        }


        T* end() {
            return _elem + size();
        }

        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const vector<U>& obj) {
            os << "Vector(size: " << obj.size() << ") [";
            for (auto i = 0; i < obj.size(); ++i) {
                if (i != 0) {
                    os << ", " << obj[i];
                }else {
                    os << obj[i];
                }
            }
            os << "]";
            return os;
        }

    };
}


#endif //MY_VECTOR_H
