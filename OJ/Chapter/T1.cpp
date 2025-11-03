#include<iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int i = 2;
        while (n != 1) {
            while (n % i == 0) {
                cout << i << endl;
                n /= i;
            }
            i++;
        }
    }
}