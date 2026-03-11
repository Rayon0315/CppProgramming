#include<iostream>
using namespace std;

bool judge(int x) {
    return x >= -2 && x <= 2;
}

int main() {
    int x, y;
    while (cin >> x >> y) {
        cout << boolalpha << (judge(x) && judge(y)) << endl;
    }
    return 0;
}