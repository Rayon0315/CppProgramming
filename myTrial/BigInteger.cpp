#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class BigInteger {
public:
    vector<int> num;
    int siz;
    
    void Print() {
        for (int i = siz-1; i >= 0; i--) {
            cout << num[i];
        }
    }
    void DeleteFrontZero() {
        while (siz != 1 && num[siz-1] == 0) { 
            num.pop_back();
            siz--;
        }
    }

    BigInteger() {
        num = {0};
        siz = 1;
    }
    BigInteger(int n) {
        num = {};
        siz = 0;
        while (n != 0) {
            num.push_back(n % 10);
            siz++;
            n /= 10;
        }
    }
    BigInteger(int x, int cnt) {
        num = {};
        siz = cnt;
        for (int i = 0; i < siz; i++) {
            num.push_back(x);
        }
    }
    BigInteger(BigInteger &x) {
        *this = x;
    }

    bool operator < (const BigInteger &x) {
        if (this->siz < x.siz) {
            return true;
        }
        if (this->siz > x.siz) {
            return false;
        }
        for (int i = this->siz - 1; i >= 0; i--) {
            if (this->num[i] >= x.num[i]) {
                return false;
            }
        }
        return true;
    }

    BigInteger operator + (const BigInteger &x) {
        BigInteger ret(0, max(this->siz, x.siz) + 1);
        int add = 0;
        for (int i = 0; i < ret.siz; i++) {
            int add1 = 0, add2 = 0;
            if (i < this->siz) add1 = this->num[i];
            if (i < x.siz) add2 = x.num[i];
            ret.num[i] = (add1 + add2 + add) % 10;
            add = (add1 + add2 + add) / 10;
        }
        ret.DeleteFrontZero();
        return ret;
    }
    BigInteger operator * (const BigInteger &x) {
        BigInteger ret(0, this->siz + x.siz + 1);
        for (int i = 0; i < this->siz; i++) {
            for (int j = 0; j < x.siz; j++) {
                ret.num[i + j] += this->num[i] * x.num[j];
                ret.num[i + j + 1] += ret.num[i + j + 1] / 10;
                ret.num[i + j] %= 10;
            }
        }
        for (int i = 0; i < ret.siz-1; i++) {
            ret.num[i + 1] += ret.num[i] / 10;
            ret.num[i] %= 10; 
        }
        ret.DeleteFrontZero();
        return ret;
    }
    BigInteger operator - (BigInteger x) {
        BigInteger A(*this), B(x);
        if (*this < x) {
            A = x, B = *this;
            cout << '-';
        }

        BigInteger ret(0, A.siz);
        for (int i = 0; i < ret.siz; i++) {
            int x = A.num[i], y = 0;
            if (i < B.siz) y = B.num[i];
            if (x - y >= 0) {
                ret.num[i] += x - y;
            } else {
                ret.num[i] += 10 + x - y;
                if (i < ret.siz) ret.num[i+1] = 0;
            }
        }

        ret.DeleteFrontZero();
        return ret;
    }
    BigInteger operator / (const int &x) {
        BigInteger ret(0, this->siz);
        int tmp = 0;
        for (int i = ret.siz - 1; i >= 0; i--) {
            ret.num[i] = (tmp * 10 + this->num[i]) / x;
            tmp = (tmp * 10 + this->num[i]) % x;
        }
        ret.DeleteFrontZero();
        return ret;
    }

};

int main() {
    BigInteger A(1024), B(1024);
    (A / 2).Print();
    return 0;
}