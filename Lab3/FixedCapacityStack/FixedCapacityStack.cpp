#include <iostream>
#include "FixedCapacityStack.h"
using namespace std;


int main() {
    FixedCapacityStack<int> mystack(5);

    for (int i = 1; i <= 5; ++i) {
        mystack.push(i);
    }

    // Вывод элементов стека
    while (!mystack.empty()) {
        cout << mystack.top() << "\n";
        mystack.pop();
    }

    if (!mystack.full()) {
        mystack.push(6);
    }
    else {
        cout << "Stack is full. Cannot push more elements." << std::endl;
    }

    return 0;
}


