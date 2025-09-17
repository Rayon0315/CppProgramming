#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (b != 0) return gcd(b, a % b);
    return a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

class RationalNumber {
public:
    int A, B; // the number should be A/B

    RationalNumber() {
        A = 0, B = 1;
    }
    RationalNumber(int x) {
        A = x, B = 1;
    }
    RationalNumber(int a, int b) {
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
    RationalNumber Inverse() {
        return RationalNumber(this->B, this->A);
    }

    RationalNumber operator + (RationalNumber x) {
        int tot = lcm(this->B, x.B);
        int mul1 = tot / x.B, mul2 = tot / this->B;
        RationalNumber ret(0);
        ret.A = this->A * mul1 + x.A * mul2;
        ret.B = tot;
        ret.Reduction();
        return ret;
    }
    RationalNumber operator * (RationalNumber x) {
        RationalNumber ret(0);
        ret.A = this->A * x.A;
        ret.B = this->B * x.B;
        ret.Reduction();
        return ret;
    }
    RationalNumber operator / (RationalNumber x) {
        return (*this) * x.Inverse();
    }
};

int main() {
    RationalNumber A(1, 7), B(3, 13);
    (A + B).Print(); cout << endl;
    (A * B).Print(); cout << endl;
    (A / B).Print(); cout << endl;
    return 0;
}