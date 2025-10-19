#include<iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int sum = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) sum += i;
        }
        string out = sum == n ? "Yes\n" : "No\n";
        cout << out;
    }
    return 0;
}