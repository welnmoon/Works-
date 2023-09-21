#include <iostream>

using namespace std;


void insertBlock(int*& currentArr, int& arrSize, const int* block, int blockSize, int index) {
    if (index < 0 || index > arrSize) {
        cout << "Недопустимый индекс для вставки блока." << endl;
        return;
    }

    int newSize = arrSize + blockSize;
    int* newArray = new int[newSize];

    for (int i = 0; i < index; ++i) {
        newArray[i] = currentArr[i];
    }

 
    for (int i = 0; i < blockSize; ++i) {
        newArray[index + i] = block[i];
    }

    for (int i = 0; i < arrSize; ++i) {
        newArray[index + blockSize + i ] = currentArr[i+index]; //начиная с остоновленного места(index+blocksize), мы до конца заполняем массив
    }

    delete[] currentArr;

 
    currentArr = newArray;
    arrSize = newSize;
}

int main() {
    setlocale(LC_ALL, "russian");
    int size;
    cout << "Введите размер динамического массива: ";
    cin >> size;

   
    int* currentArray = new int[size];

    int blockSize;
    cout << "Введите размер блока: ";
    cin >> blockSize;
    int* blockArray = new int[blockSize];

  
    cout << "Введите элементы динамического массива: ";
    for (int i = 0; i < size; ++i) {
        cin >> currentArray[i];
    }

    cout << "Введите элементы блока: ";
    for (int i = 0; i < blockSize; ++i) {
        cin >> blockArray[i];
    }

    int index;
    cout << "Введите индекс для вставки блока: ";
    cin >> index;

  
    insertBlock(currentArray, size, blockArray, blockSize, index);


    cout << "Обновленный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << currentArray[i] << " ";
    }
    cout << endl;

    delete[] currentArray;
    delete[] blockArray;

    return 0;
}


