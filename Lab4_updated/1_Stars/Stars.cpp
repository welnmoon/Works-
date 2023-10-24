#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    string newStr;
    for (int i = 0; i < str.length(); ++i) {
        newStr += str[i];
        if (i < str.length() - 1) {
            newStr += "*";
        }
    }

   cout << newStr << endl;

    return 0;
}