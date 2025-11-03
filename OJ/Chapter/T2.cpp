#include<iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        cout << (n % 3 == 2 && n % 5 == 3 && n % 7 == 2) << endl;
    }
}