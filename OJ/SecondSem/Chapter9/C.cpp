#include <iostream>
using namespace std;

class Integer {
protected:
    int n;

public:
    Integer (int N = 0) : n(N) {}
};

class Vector : public Integer {
protected:
    int *v;

public:
    Vector (int N = 0) : Integer(N) {
        if (n == 0) {
            v = nullptr;
        } else {
            v = new int[n];
        }
    }

    Vector (const Vector &oth) {
        n = oth.n;
        v = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = oth.v[i];
        }
    }

    Vector operator + (const Vector &oth) {
        Vector res(n);

        for (int i = 0; i < n; i++) {
            res.v[i] = v[i] + oth.v[i];
        }

        return res;
    }

    Vector operator - (const Vector &oth) {
        Vector res(n);
        
        for (int i = 0; i < n; i++) {
            res.v[i] = v[i] - oth.v[i];
        }
        
        return res;
    }

    int operator * (const Vector &oth) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += v[i] * oth.v[i];
        }
        return res;
    }

    void init() {
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
    }
    
    void print() {
        for (int i = 0; i < n; i++) {
            cout << v[i];
            if (i != n - 1) cout << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    while (cin >> n) {
        Vector A(n), B(n);
        A.init();
        B.init();

        (A + B).print();
        (A - B).print();
        cout << A * B << endl;
    }

    return 0;
}