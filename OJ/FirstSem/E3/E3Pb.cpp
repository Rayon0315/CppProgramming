#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

float sumPow(float n, int x) {
    float sum = 0;
    for (int i = 1; i <= n; i++) sum += pow(i, x);
    //cout << n << " " << x << " " << sum << endl;
    return sum;
}

int main() {
    float m, n, p;
    while (cin >> m >> n >> p) {
        cout << fixed << setprecision(4) << (sumPow(m, 1) + sumPow(n, 3)) / sumPow(p, 5) << endl;
    }
    return 0;
}