#include<iostream>
using namespace std;

int main() {
    int n1 = 1, n2 = 2, n3;
    n3 = n1;
    cout << "n1 = " << n1 << '\x20' << "n2 = " << n2 << '\x20' << "n3 = " << n3 << endl;
    cout << "n1 >= n2: " << (n1 >= n2) << endl;
    cout << "n1 <= n2: " << (n1 <= n2) << endl;
    cout << "n1 == n2: " << (n1 == n2) << endl;
    cout << "n1 == n3: " << (n1 == n3) << endl;

    n2 = 5, n3 = 3;
    cout << "n1 = " << n1 << '\x20' << "n2 = " << n2 << '\x20' << "n3 = " << n3 << endl;
    cout << "n1 <= n2 <= n3: " << (n1 <= n2 <= n3) << endl; //该语法不成立
    return 0;
}