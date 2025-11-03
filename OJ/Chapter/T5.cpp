#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double sh(double x) {
    return (exp(x) - exp(-x)) / 2.;
}

double y(double x) {
    return sh(1. + sh(x)) / (sh(2.*x) + sh(3.*x));
}

int main() {
    double x;
    while (cin >> x) {
        cout << fixed << setprecision(4) << y(x) << endl;
    }
    return 0;
}