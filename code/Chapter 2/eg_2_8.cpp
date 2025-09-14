#include<iostream>
using namespace std;

int main() {
    int cnt1 = 0, cnt2 = 5;
    int tot = 0;

    tot = cnt1++ + cnt2++;
    cout << "cnt1 = " << cnt1 << endl;
    cout << "cnt2 = " << cnt2 << endl;
    cout << "tot = " << tot << endl;

    tot = ++cnt1 + ++cnt2;
    cout << "cnt1 = " << cnt1 << endl;
    cout << "cnt2 = " << cnt2 << endl;
    cout << "tot = " << tot << endl;
    return 0;
}