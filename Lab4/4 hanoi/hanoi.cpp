#include <iostream>
using namespace std;

void hanoi(int n, int i, int k) {
	if (n == 1) {
		cout << "1 Move disk " << n << " from pin " << i << " to " << k << endl;
	}
	else {
		int tmp = 6 - i - k; // 1+2+3 = 6. 
		hanoi(n - 1, i, tmp);
		cout << "Move disk " << n << " from pin " << i << " to " << k << endl;
		hanoi(n - 1, tmp, k);
	}
}

int main() {
	hanoi(3, 1, 2);
	return 0;
}
