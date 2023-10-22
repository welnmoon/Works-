#include <iostream>

using namespace std;

long long fibonacci(int N, long long a = 0, long long b = 1) {
    if (N == 0) {
        return a;
    }
    return fibonacci(N - 1, b, a + b);
}

int main() {
    int N;
    cout << "N: ";
    cin >> N;

    if (N >= 0 && N <= 30) {
        int result = fibonacci(N);
        cout << "Фибоначчи N: " << result << endl;
    } else {
        cout << "Некорректный ввод. N должно быть в диапазоне от 0 до 30." << endl;
    }

    return 0;
}
