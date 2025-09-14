#include<iostream>
using namespace std;

int main() {
    int n1 = 0, n2 = 0, n3 = 0;
    bool r1, r2, r3;

    r1 = n1++ && n2++;
    cout << "r1 = " << r1 << " n1 = " << n1 << " n2 = " << n2 << endl;
    
    r2 = n1-- || n3--;
    cout << "r2 = " << r2 << " n1 = " << n1 << " n3 = " << n3 << endl;

    r3 = ++n1 || ++n2 && --n3;
    cout << "r3 = " << r3 << " n1 = " << n1 << " n2 = " << n2 << " n3 = " << n3 << endl;
    return 0;
}