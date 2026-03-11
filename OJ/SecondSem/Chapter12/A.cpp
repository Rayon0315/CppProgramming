#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265;

int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            double rad = (double)i / 180. * PI;
            cout << setw(3) << left << i
                << fixed << setprecision(5)
                << setw(10) << left << sin(rad)
                << setw(10) << left << cos(rad)
                << setw(10) << left << tan(rad) << endl;
        }
    }
    return 0;
}