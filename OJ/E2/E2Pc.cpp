#include<iostream>
#include<bitset>
#include<iomanip>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        cout << " " << bitset<8>(n);
        cout << " " << hex << setw(2) << setfill('0') << n << endl;
    }
    return 0;
}