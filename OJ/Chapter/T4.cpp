#include<iostream>
using namespace std;

int mx(int a, int b, int c) {
    return (a > b && a > c) ? a : (b > c ? b : c);
}

int mn(int a, int b, int c) {
    return (a < b && a < c) ? a : (b < c ? b : c);
}

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        cout << mn(a, b, c) << " "
             << a + b + c - mx(a, b, c) - mn(a, b, c) << " "
             << mx(a, b, c) << endl;
    }
    return 0;
}