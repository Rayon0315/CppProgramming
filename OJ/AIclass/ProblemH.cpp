#include <bits/stdc++.h>
using namespace std;

int cur;

long double minPay(long long &d, int m) {

    long double interest = (long double)d * 0.015L;  

    long double tmp = (long double)d + interest;

    long long ret = (long long)ceill(tmp * 0.1L);
    if (ret < 100) ret = 100;

    cout << "月" << cur << "最低还款：" << ret << "\n";

    long double nxt = tmp - ret;
    d = (long long) llroundl(nxt);

    return (double)interest;
}

int main() {

    long long d;
    int m;
    double ti;

    while (cin >> d >> m) {

        ti = 0;
        for (cur = 1; cur <= m; cur++) {
            ti += minPay(d, m);
        }

        cout << fixed << setprecision(2)
             << "总利息：" << ti << "\n";
    }
    return 0;
}
