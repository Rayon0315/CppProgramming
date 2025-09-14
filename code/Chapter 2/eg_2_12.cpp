#include<iostream>
using namespace std;

int main() {
    int a, b;
    a = b = 10;
    cout << a << '\t' << b << endl;

    (a = b) = 50;
    cout << a << '\t' << b << endl;

    a += b;
    cout << a << '\t' << b << endl;

    a /= b;
    cout << a << '\t' << b << endl;
    return 0;
}