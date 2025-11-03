#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double calc(double t, int x) {
    double sum = 0;
    for (double i = 1.; i <= t; i++) {
        sum += pow(i, x);
    }
    return sum;
}

int main() {
    double m, n, p;
    while (cin >> m >> n >> p) {
        cout << fixed << setprecision(4) << (calc(m, 1) + calc(n, 3)) / calc(p, 5) << endl;
    }
    return 0;
}