//
// Created by cytech on 29/03/24.
//

#ifndef STACK_H
#define STACK_H
#include <cstddef>
#include <cstdlib>
#include <ostream>


namespace my {
    template<typename T>
    class stack {
        T* _elem;
        T* _top;
        std::size_t _size{};

    public:
        explicit stack(const std::size_t& size): _size(size) {
            _elem = static_cast<T *>(malloc(size * sizeof(T)));
            _top = _elem;
        }

        ~stack() {
            free(_elem);
        }

        [[nodiscard]] std::size_t size() const {
            return _size;
        }

        [[nodiscard]] bool empty() const {
            return _top == _elem;
        }

        T peek() const {
            if (!empty()) {
                return *(_top - 1);
            }
            return *_top;
        }

        void push(const T& elem) {
            if (_top != _elem + _size) {
                *_top++ = elem;
            }
        }

        T pop() {
            if (!empty()) {
                return *--_top;
            }
            return *_top;
        }

        friend std::ostream& operator<<(std::ostream& os, const stack& obj) {
            os << "stack: size = " << obj._size << ", elems = [";
            for (T* i = obj._elem; i != obj._top; ++i) {
                if (i == obj._elem) {
                    os << *i;
                } else {
                    os << ", " << *i;
                }
            }
            os << "]";
            return os;
        }
    };
}


#endif //STACK_H
