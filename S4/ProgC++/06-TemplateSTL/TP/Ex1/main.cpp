

#include <iostream>

#include "my_stack.h"

using my::stack, std::cout, std::endl;

int main() {

    stack<int> istack(12);
    cout << "Stack size: " << istack.size() << endl;
;
    cout << "Is istack empty: " << istack.empty() << endl;;

    cout << "Stack push" << endl;
    istack.push(25);

    cout << "Is istack empty: " << istack.empty() << endl;;
    cout << "Top: " << istack.peek() << endl;;


    istack.push(55);
    istack.push(495);
    istack.push(6174);
    istack.push(12);

    cout << istack << endl;


    cout << "Stack pop: " << istack.pop() << endl;
    cout << istack << endl;

    return 0;
}
