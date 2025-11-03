#include<iostream>
#include<vector>
using namespace std;

class Matrix {
private:
    int m, n;
    vector<vector<int>> num;

public:
    Matrix () {
        m = n = 0;
        num.clear();
    }
    Matrix (int M, int N) : m(M), n(N) {
        for (int i = 0; i < m; i++) {
            vector<int> v(n, 0);
            num.push_back(v);
        }
    }

    int& operator() (int &i, int &j) {
        return num[i][j];
    }

    Matrix transpose() {
        Matrix ret(n, m);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ret(j, i) = num[i][j];
        return ret;
    }
    Matrix operator - () {
        Matrix ret(m, n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ret(i, j) = -num[i][j];
        return ret;
    }

    Matrix operator + (Matrix A) {
        if (m != A.m || n != A.n) {
            cout << "ERROR: m or n is not the same!" << endl;
            return Matrix();
        }
        Matrix ret(m, n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ret(i, j) = num[i][j] + A(i, j);
        return ret;
    }
    Matrix operator - (Matrix A) {
        if (m != A.m || n != A.n) {
            cout << "ERROR: m or n is not the same!" << endl;
            return Matrix();
        }
        return (*this) + (-A);
    }

    Matrix operator * (Matrix A) {
        if (n != A.m) {
            cout << "ERROR: cannot do it!" << endl;
            return Matrix();
        }
        Matrix ret(m, A.n);
        int M = m, N = n, P = A.n;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < P; j++)
                for (int k = 0; k < N; k++)
                    ret(i, j) += num[i][k] * A(k, j);
        return ret;
    }

    friend istream& operator >> (istream &in, Matrix &A) {
        in >> A.m >> A.n;
        A.num.clear();
        for (int i = 0; i < A.m; i++) {
            vector<int> v(A.n, 0);
            A.num.push_back(v);
            for (int j = 0; j < A.n; j++) {
                in >> A(i, j);
            }
        }
        return in;
    }
    friend ostream& operator << (ostream &out, Matrix &A) {
        out << "SIZE: " << A.m << "*" << A.n << endl;
        for (int i = 0; i < A.m; i++) {
            for (int j = 0; j < A.n; j++) {
                out << A(i, j) << " ";
            }
            out << endl;
        }
        return out;
    }
};

int main() {
    Matrix A, B, C;
    cin >> A >> B;
    C = A*B;
    cout << C;
    return 0;
}