#include <iostream>
#include <cstring>
using namespace std;

string inp;
int buc[10];

int main() {
    while (cin >> inp) {
        memset(buc, 0, sizeof(buc));

        for (int i = inp.size() - 1; i >= 0; i--) {
            if (!buc[inp[i] - '0']) {
                buc[inp[i] - '0']++;
                cout << inp[i];
            }
        }

        cout << endl;
    }
}