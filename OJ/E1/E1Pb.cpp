#include<iostream>
using namespace std;

int myMin(int x, int y) {
    return x <= y ? x : y;
}

int main() {
    int x, y, z;
    while (cin >> x >> y >> z) {
        cout << myMin(myMin(x, y), z) << endl;
    }
    return 0;
}