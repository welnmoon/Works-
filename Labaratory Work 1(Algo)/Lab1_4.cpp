#include <iostream>
using namespace std;

void addBlock(int*& currentArr, int& arrSize, int* block, int blockSize) {
    int newSize = arrSize + blockSize;
    int* newArray = new int[newSize];

    for (int i = 0; i < arrSize; ++i) {
        newArray[i] = currentArr[i];
    }
    for (int i = 0; i < blockSize; ++i) {
        newArray[arrSize + i] = block[i];
    }

    delete[] currentArr;

    currentArr = newArray;
    arrSize = newSize;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "Введите размер текущего массива: ";
    cin >> size;

    int* currentArray = new int[size];

    int blockSize;
    cout << "Введите размер блока: ";
    cin >> blockSize;
    int* blockArray = new int[blockSize];

    cout << "Введите элементы текущего массива: ";
    for (int i = 0; i < size; ++i) {
        cin >> currentArray[i];
    }

    cout << "Введите элементы блока: ";
    for (int i = 0; i < blockSize; ++i) {
        cin >> blockArray[i];
    }

    addBlock(currentArray, size, blockArray, blockSize);

    cout << "Обновленный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << currentArray[i] << " ";
    }
    cout << endl;

    delete[] currentArray;
    delete[] blockArray;

    return 0;
}

