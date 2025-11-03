#include<iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += n % i == 0 ? i : 0;
        }
        cout << (sum == n) << endl;
    }
}