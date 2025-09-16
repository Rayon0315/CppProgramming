#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (b != 0) return gcd(b, a % b);
    return a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

class RealNumber {
public:
    int A, B; // the number should be A/B

    RealNumber() {
        A = 0, B = 1;
    }
    RealNumber(int x) {
        A = x, B = 1;
    }
    RealNumber(int a, int b) {
        A = a, B = b;
        this->Reduction();
    }

    void Print() {
        if (B == 1) cout << A;
        else cout << A << "/" << B;
    }

    void Reduction() {
        int x = gcd(A, B);
        A /= x;
        B /= x;
    }
    RealNumber Inverse() {
        return RealNumber(this->B, this->A);
    }

    RealNumber operator + (RealNumber x) {
        int tot = lcm(this->B, x.B);
        int mul1 = tot / x.B, mul2 = tot / this->B;
        RealNumber ret(0);
        ret.A = this->A * mul1 + x.A * mul2;
        ret.B = tot;
        ret.Reduction();
        return ret;
    }
    RealNumber operator * (RealNumber x) {
        RealNumber ret(0);
        ret.A = this->A * x.A;
        ret.B = this->B * x.B;
        ret.Reduction();
        return ret;
    }
    RealNumber operator / (RealNumber x) {
        return (*this) * x.Inverse();
    }
};

int main() {
}