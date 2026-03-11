#include<iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        while (n) {
            cout << "  " << n % 10;
            n /= 10;
        }
        cout << endl;
    }
}