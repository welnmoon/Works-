#include <iostream>
using namespace std;

void hanoiii(int n, int from, int to, int temp)
{
    if (n == 1)
    {
        cout << "1 " << from << " " << to << "\n";
        return;
    }

    hanoiii(n - 1, from, temp, to);

    cout << n << " " << from << " " << to << "\n";

    hanoiii(n - 1, temp, to, from);
}

int main()
{
    int n;
    cin >> n;
    hanoiii(n, 1, 3, 2);
    return 0;
}
