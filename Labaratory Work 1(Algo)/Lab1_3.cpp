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

    int* newArr = new int[M];
    int n = 0;

    for (int i = 0; i < M; i++) {
        bool isDuplicate = false;

        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            newArr[n] = A[i];
            n++;
        }
    }

    cout << "Не повторяющиеся элементы из массива A, которых нет в B:" << endl;
    for (int i = 0; i < n; i++) {
        cout << newArr[i] << " ";
    }

    delete[] A;
    delete[] B;
    delete[] newArr;

    return 0;
}
