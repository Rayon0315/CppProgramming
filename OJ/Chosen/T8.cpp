#include<iostream>
#include<cmath>
using namespace std;

int main() {
    string A, B;
    while (cin >> A >> B) {
        if (A[0] != B[0]) {
            cout << -1 << endl;
        } else {
            int len = 0;
            for (int i = 0; i < min(A.size(), B.size()); i++) {
                if (A[i] == B[i]) len++;
                else break;
            }
            cout << A.substr(0, len) << endl;
        }
    }
}