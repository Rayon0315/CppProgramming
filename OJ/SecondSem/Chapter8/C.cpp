#include <iostream>
using namespace std;

class Vector {
private:
    int siz;
    int* data;

public:
    Vector(int N = 0) {
        if (N == 0) {
            siz = 0;
            data = nullptr;
        } else {
            siz = N;
            data = new int[siz];
            for (int i = 0; i < siz; i++)
                data[i] = 0;
        }
    }

    void initVector(int n) {
        siz = n;
        data = new int[siz];
        for (int i = 0; i < siz; i++) {
            cin >> data[i];
        }
    }

    Vector operator + (const Vector &oth) {
        Vector ret(siz);
        for (int i = 0; i < siz; i++) {
            ret.data[i] = data[i] + oth.data[i];
        }
        return ret;
    }

    Vector operator - (const Vector &oth) {
        Vector ret(siz);
        for (int i = 0; i < siz; i++) {
            ret.data[i] = data[i] - oth.data[i];
        }
        return ret;
    }

    long long operator * (const Vector &oth) {
        long long res = 0;
        for (int i = 0; i < siz; i++) {
            res += data[i] * oth.data[i];
        }
        return res;
    }

    void print() {
        for (int i = 0; i < siz; i++) {
            cout << data[i];
            if (i != siz - 1) cout << " ";
        }
        cout << endl;
    }
};

int main() {
    char op; int n;
    while (cin >> op >> n) {
        Vector A, B;
        A.initVector(n);
        B.initVector(n);

        switch (op) {
            case '+': (A + B).print(); break;
            case '-': (A - B).print(); break;
            case '*': cout << (A * B) << endl; break;
        }
    }
    return 0;
}