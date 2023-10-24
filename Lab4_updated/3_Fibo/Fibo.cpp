#include <iostream>
using namespace std;

int fibo(int N) {
	if (N <= 1) {
		return N;
	}
	else {
		return fibo(N - 1) + fibo(N - 2);
	}
}

int main() {
	int N;
	cin >> N;

	cout<<fibo(N);
	
}