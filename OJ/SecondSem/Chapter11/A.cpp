#include <iostream>
#include <iomanip>
using namespace std;

const int n = 3;

template<typename T>
T average(T* arr) {
    T sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

int a[3];
double b[3];

int main() {
    while (cin >> a[0] >> a[1] >> a[2]) {
        cout << average(a) << endl;

        cin >> b[0] >> b[1] >> b[2];
        cout << fixed << setprecision(3) << average(b) << endl;
    }
    return 0;
}