#include <iostream>
using namespace std;

int NOD(int first, int second)
{
	while (first != second)
	{
		if (first > second) first -= second;
		else second -= first;
	}
	return first;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int first, second;
	cout << "Введите первое значение" << endl;
	cin >> first;
	cout << "Введите второе значение" << endl;
	cin >> second;
	cout << "НОД(" << first << ", " << second << ")=" << NOD(first, second) << endl;
	return 0;
}