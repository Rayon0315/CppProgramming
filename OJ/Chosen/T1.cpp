#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        for (char c : s) {
            cout << c << '*';
        }
        cout << endl;
    }
    return 0;
}