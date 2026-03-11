#include<iostream>
#include<algorithm>
using namespace std;

class Node {
public:
    int idx, num;
    Node () : idx(0), num(0) {}
    Node(int i, int n) : idx(i), num(n) {}
};

bool cmp(Node x, Node y) {
    return x.num > y.num;
}


int main() {
    int n = 10;
    Node A[10];
    for (int i = 0; i < n; i++) {
        cin >> A[i].num;
        A[i].idx = i;
    }
    sort(A, A+n, cmp);
    for (int i = 0; i < n; i++) {
        cout << A[i].num << " " << A[i].idx << endl;
    }
    return 0;
}