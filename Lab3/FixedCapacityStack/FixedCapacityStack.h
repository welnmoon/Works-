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
    if (!full()) {
        a[n++] = item;
    }
    else {
        cout<<"Stack is full";
    }
}

template <typename T>
T FixedCapacityStack<T>::pop() {
    if (!empty()) {
        return a[--n];
    }
    cout<<"Stack is empty";
}

template <typename T>
T FixedCapacityStack<T>::top() const {
    if (!empty()) {
        return a[n - 1];
    }
   cout<<"Stack is empty";
}
#endif // FIXEDCAPACITYSTACK_H