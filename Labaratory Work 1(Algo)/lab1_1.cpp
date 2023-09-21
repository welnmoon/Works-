#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    int M, N;
    cout << "Введите размеры массивов: ";
    cin >> M >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Введите элементы массива A:" << endl;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int* newArr = new int[M < N ? M : N]; 
    int n = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                bool alreadyHere = false;
                for (int b = 0; b < n; b++) {
                    if (newArr[b] == A[i]) {
                        alreadyHere = true;
                        break;
                    }
                }
                if (!alreadyHere) {
                    newArr[n++] = A[i];
                }
            }
        }
    }

    cout << "Общие элементы массивов без повторений:" << endl;
    for (int i = 0; i < n; i++) {
        cout << newArr[i] << " ";
    }

    delete[] A;
    delete[] B;
    delete[] newArr;

    return 0;
}
