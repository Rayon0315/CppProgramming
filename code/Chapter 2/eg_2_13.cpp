#include<iostream>
using namespace std;

int main() {
    int n1 = 10, n2 = 20, max1;
    max1 = n1 >= n2 ? n1++ : n2++;
    cout << "n1 = " << n1 << " n2 = " << n2 << endl;
    cout << "max1 = " << max1 << endl;

    char ch1 = 'A';
    char ch2;
    ch2 = (ch1 >= 'A' && ch1 <= 'Z') ? ch1 + 32 : ch1; // 'a' - 'A' = 32
    cout << "ch2 = " << ch2 << endl;

    int max2;
    max2 = max1 >= ch1 ? max1 : ch1;
    cout << "max2 = " << max2 << endl;
    
    return 0;
}