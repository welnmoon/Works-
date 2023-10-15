#include <iostream>
#include "FixedCapacityStack.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "ru");
    FixedCapacityStack<int> mystack(5);

    for (int i = 1; i <= 5; ++i) {
        mystack.push(i);
    }

    cout << mystack;

    if (!mystack.full()) {
        mystack.push(6);
    }
    else {
        cout << "Стэк полон!" << std::endl;
    }
    mystack.push(8);

    return 0;
}


