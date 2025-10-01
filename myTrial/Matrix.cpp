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
//一个树状数组类，O(log n)实现动态区间查询并且空间为O(n)

BinaryIndexedTree::BinaryIndexedTree () {
    maxNode = 0;
    node.clear();
}
//初始化函数

BinaryIndexedTree::BinaryIndexedTree (int maxNodeInput) : maxNode(maxNodeInput) {
    node.clear();
    for (int i = 0; i <= maxNode; i++) {
        node.push_back(0);
    }
}
//带最大结点的初始化函数

void BinaryIndexedTree::update(int x) {
    while (x <= maxNode) {
        node[x] ++;
        x += lowbit(x);
    }
}
//更新0~x区间的值

int BinaryIndexedTree::query(int x) {
    int sum = 0;
    while (x) {
        sum += node[x];
        x -= lowbit(x);
    }
    return sum;
}
//计算0~x区间的值

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
//初始化函数

Matrix::Matrix (int N) : n(N) {
    arr.clear();
    vector<int> cur(n, 0);
    for (int i = 0; i < n; i++) {
        arr.push_back(cur);
        arr[i][i] = 1;
    }
}
//含N的初始化函数，是单位矩阵

Matrix::Matrix (vector<vector<int>> brr) {
    n = brr[0].size();
    arr = brr;
}
//含矩阵的初始化函数

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
//带输入的初始化函数

void Matrix::Print() {
    cout << "Here is the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
//输出函数

int NegativeOnePow(int n) {
    return n % 2 == 1 ? -1 : 1;
}
//为了计算-1^逆序数次方

int CountReverseOrder(int n, vector<int> x) {
    int sum = 0;
    BinaryIndexedTree T(n);
    for (int i = n - 1; i >= 0; i--) {
        sum += T.query(x[i] + 1);
        T.update(x[i] + 1);
    }
    return sum;
}
//逆序数计算：树状数组倒序遍历

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
//计算行列式，通过next_permutation函数进行全排列

int main() {
    Matrix A;
    A.Init();
    cout << A.det() << endl;
    return 0;
}