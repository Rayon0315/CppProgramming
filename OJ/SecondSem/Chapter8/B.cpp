#include <iostream>
using namespace std;

class Integer {
private:
    int num;

public:
    Integer(int N = 0) : num(N) {}

    Integer operator + (const Integer &oth) {
        Integer ret(num + oth.num);
        return ret;
    }

    Integer operator - (const Integer &oth) {
        Integer ret(num - oth.num);
        return ret;
    }

    Integer operator * (const Integer &oth) {
        Integer ret(num * oth.num);
        return ret;
    }

    Integer operator / (const Integer &oth) {
        Integer ret(num / oth.num);
        return ret;
    }

    void print() {
        cout << num << endl;
    }
};

int main() {
    char op; int a, b;
    while (cin >> op >> a >> b) {
        Integer A(a), B(b);
        Integer res;
        switch (op) {
            case '+': res = A + B; break;
            case '-': res = A - B; break;
            case '*': res = A * B; break;
            case '/': res = A / B; break;
        }
        res.print();
    }
}