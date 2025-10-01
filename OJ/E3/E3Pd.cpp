#include<iostream>
using namespace std;

string output(bool x) {
    return x ? "YES" : "NO";
}

int main() {
    string n;
    while (cin >> n) {
        int i = 0, j = n.size() - 1;
        bool res = 1;
        while (i <= j) {
            if (n[i] != n[j]) {
                res = 0;
                break;
            }
            i++, j--;
        }
        cout << output(res) << endl;
    }
    return 0;
}