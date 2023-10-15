#ifndef FIXEDCAPACITYSTACK_H
#define FIXEDCAPACITYSTACK_H

#include <iostream>
template <typename T>
class FixedCapacityStack {
private:
    T* a;
    int n;
    int capacity;

public:
    FixedCapacityStack(int capacity);
    ~FixedCapacityStack();

    bool empty() const;
    bool full() const;
    void push(T item);
    T pop();
    T top() const;

    friend std::ostream& operator<<(std::ostream& os, const FixedCapacityStack<T>& stack) {
        for (int i = stack.n - 1; i >= 0; --i) {
            os << stack.a[i] << "\n";
        }
        return os;
    }
};

template <typename T>
FixedCapacityStack<T>::FixedCapacityStack(int capacity) : capacity(capacity), n(0) {
    a = new T[capacity];
}

template <typename T>
FixedCapacityStack<T>::~FixedCapacityStack() {
    delete[] a;
}

template <typename T>
bool FixedCapacityStack<T>::empty() const {
    if (n == 0) {
        return true;
    }
    else return false;
}

template <typename T>
bool FixedCapacityStack<T>::full() const {
    if (n == capacity) {
        return true;
    }
    else return false;
}

template <typename T>
void FixedCapacityStack<T>::push(T item) {
    setlocale(LC_ALL, "ru");
    if (!full()) {
        a[n++] = item;
    }
    else {
        cout<<"Стэк полный!";
    }
}

template <typename T>
T FixedCapacityStack<T>::pop() {
    setlocale(LC_ALL, "ru");
    if (!empty()) {
        return a[--n];
    }
    cout<<"Стэк пустой!";
}

template <typename T>
T FixedCapacityStack<T>::top() const {
    setlocale(LC_ALL, "ru");
    if (!empty()) {
        return a[n - 1];
    }
   cout<<"Стэк пустой!";
}
#endif 