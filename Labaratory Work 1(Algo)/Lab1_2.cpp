#include <iostream>
using namespace std;

int main() {
    int M, N;
    cout << "Введите размеры массивов: ";
    cin >> M >> N;

    int A[M], B[N];

    cout << "Элементы массива A:" << endl;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Элементы массива B:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int newArr[M]; 
    int n = 0;

    for (int i = 0; i < M; i++) {

        // Проверка совпадений в двух массивах
        bool isDuplicate = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                isDuplicate = true;
                break;
            }
        }

        // Проверка на то существует ли УЖЕ этот элемент в новом массиве
        if (!isDuplicate) {
           bool alreadyHere = false;
           for (int k = 0; k <= n; k++) {
           if (newArr[k] == A[i]) {
             alreadyHere = true;
             break;
            }
            }
           if (!alreadyHere) {
              newArr[n] = A[i]; 
              n++;
            }
        }

    }

    cout << "Не повторяющиеся элементы из массива A, которых нет в B:" << endl;
    for (int i = 0; i < n; i++) {
        cout << newArr[i] << " ";
    }

    return 0;
}


