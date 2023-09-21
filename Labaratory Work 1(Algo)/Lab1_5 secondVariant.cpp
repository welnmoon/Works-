#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int mainArraySize, blockArraySize;
	cout << "Введите размер для главного массива:" << endl;
	cin >> mainArraySize;
	cout << "Введите размер для добавочного массива:" << endl;
	cin >> blockArraySize;

	int* mainArray = new int[mainArraySize];
	int* blockArray = new int[blockArraySize];

	cout << "элементы главного массива:" << endl;

	for (int i = 0; i < mainArraySize; ++i) {
		cin >> mainArray[i];
	}
	cout << "элементы добавочного массива: " << endl;
	for (int i = 0; i < blockArraySize; ++i) {
		cin >> blockArray[i];
	}

	int indexForPaste;
	cout << "Введите индекс для главного массива для вставки добавочного массива:" << endl;
	cin >> indexForPaste;

	if (indexForPaste<0 || indexForPaste>mainArraySize) {
		cout << "Вы ввели не корректный индекс";
		return 1;
	}
	int newArraySize = mainArraySize + blockArraySize;
	int* newArray = new int[newArraySize];

	for (int i = 0; i < indexForPaste; ++i) {
		newArray[i] = mainArray[i];
	}
	for (int i = indexForPaste; i < indexForPaste + blockArraySize; ++i) {
		newArray[i] = blockArray[i - indexForPaste];
	}

	for (int i = indexForPaste + blockArraySize; i < newArraySize; ++i) {
		newArray[i] = mainArray[i - blockArraySize];
	}

	for (int i = 0; i < newArraySize; ++i) {
		cout << newArray[i] << "\t";
	}

	delete[] mainArray;
	delete[] blockArray;
	return 0;


}