#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lowbit(int x) {
    return x & (-x);
}

class BinaryIndexedTree {
private:
    vector<int> node;
    int maxNode;

public:
    BinaryIndexedTree ();
    BinaryIndexedTree (int maxNodeInput);
    void update(int x);
    int query(int x);
};


BinaryIndexedTree::BinaryIndexedTree () {
    maxNode = 0;
    node.clear();
}

BinaryIndexedTree::BinaryIndexedTree (int maxNodeInput) : maxNode(maxNodeInput) {
    node.clear();
    for (int i = 0; i <= maxNode; i++) {
        node.push_back(0);
    }
}

void BinaryIndexedTree::update(int x) {
    while (x <= maxNode) {
        node[x] ++;
        x += lowbit(x);
    }
}

int BinaryIndexedTree::query(int x) {
    int sum = 0;
    while (x) {
        sum += node[x];
        x -= lowbit(x);
    }
    return sum;
}

class Matrix {
private:
    vector<vector<int>> arr;
    int n;

public:
    Matrix ();
    Matrix (int n);
    Matrix (vector<vector<int>> brr);
    void Init();
    void Print();
    int det();
};

Matrix::Matrix () {
    arr.clear();
    arr.push_back({1});
    n = 1;
}

Matrix::Matrix (int N) : n(N) {
    arr.clear();
    vector<int> cur(n, 0);
    for (int i = 0; i < n; i++) {
        arr.push_back(cur);
        arr[i][i] = 1;
    }
}

Matrix::Matrix (vector<vector<int>> brr) {
    n = brr[0].size();
    arr = brr;
}

void Matrix::Init() {
    cout << "Please Input n:"; cin >> n;
    cout << "Please Input the Matrix" << "(" << n << "*" << n << ")" << endl;
    arr.clear();
    for (int i = 0; i < n; i++) {
        vector<int> cur;
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            cur.push_back(x);
        }
        arr.push_back(cur);
    }
}

void Matrix::Print() {
    cout << "Here is the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int NegativeOnePow(int n) {
    return n % 2 == 1 ? -1 : 1;
}
int CountReverseOrder(int n, vector<int> x) {
    int sum = 0;
    BinaryIndexedTree T(n);
    for (int i = n - 1; i >= 0; i--) {
        sum += T.query(x[i] + 1);
        T.update(x[i] + 1);
    }
    return sum;
}

int Matrix::det() {
    int res = 0;
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        tmp.push_back(i);
    }
    do {
        int mul = 1;
        for (int i = 0; i < n; i++) {
            mul *= arr[i][tmp[i]];
        }
        res += mul * NegativeOnePow(CountReverseOrder(n, tmp));
    } while (next_permutation(tmp.begin(), tmp.end()));
    return res;
}

int main() {
    Matrix A({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    A.Print();
    cout << A.det() << endl;
    return 0;
}