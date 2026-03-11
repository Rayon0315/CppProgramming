#include<iostream>
#include<iomanip>
#include<cstring>
#include<iomanip>
using namespace std;

float p[105];
float P(int n, float x) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (p[n]) return p[n];
    return p[n] = ((2*n-1)*x*P(n-1, x) - (n-1) * P(n-2, x)) / (float)(n);
}

int main() {
    float x;
    int n;
    while (cin >> x >> n) {
        memset(p, 0, sizeof(p));
        p[0] = 1, p[1] = x;
        cout << fixed << setprecision(2) << P(n, x) << endl;
    }
}