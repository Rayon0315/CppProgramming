#include<iostream>
#include<vector>
using namespace std;

vector<unsigned long long> fib;

int main() {
    fib.push_back(1);
    fib.push_back(1);
    
    int n;
    while (cin >> n) {
        if (fib.size() <= n) {
            while (fib.size() <= n) {
                fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
            }
            cout << fib[n] << endl;
        } else {
            cout << fib[n] << endl;
        }
    }

    return 0;
}