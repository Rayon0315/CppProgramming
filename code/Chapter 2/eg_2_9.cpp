#include<iostream>
using namespace std;

int main() {
    int a;
    char c;
    double x;

    a = 2.0 / 4;
    x = 2.0 / 4;
    cout << a << '\t' << x << endl;

    a = 3 + 'A';
    c = 3 + 'A';
    cout << a << '\t' << c << endl;
    cout << 3 + 'A' << endl;
    return 0;
}