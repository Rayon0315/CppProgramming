#include<iostream>
using namespace std;

int main() {
    int T;
    while (cin >> T) {
        while (T--) {
            int n; cin >> n;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                int c; cin >> c;
                if(c) sum += (1 << (n-i-1));
            }
            cout << sum << endl;
        }
    }
}