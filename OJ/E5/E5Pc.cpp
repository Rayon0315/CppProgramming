#include<iostream>
#include<cmath>
using namespace std;

struct Node {
    int x, y;
    
    Node () : x(0), y(0) {}
    Node (int X, int Y) : x(X), y(Y) {}
    
    friend istream& operator >> (istream &in, Node &A) {
        in >> A.x >> A.y;
        return in;
    }
};

/*
正方形判定条件（通过斜率证明）：
1.对角线相互垂直 ---> 筝形
2.相邻边相互垂直 ---> 矩形
枚举可能的相对位置：
AB  AC  AD  AB
CD  BD  BC  DC
存在一种符合要求即可
*/

bool JudgeVert(Node P, Node Q, Node S, Node T) {
    //判断PQ 和 ST的斜率关系
    return (P.x-Q.x)*(S.x-T.x) + (P.y-Q.y)*(S.y-T.y) == 0;
}

bool Judge(Node A, Node B, Node C, Node D) {
    return JudgeVert(A, D, B, C) && JudgeVert(A, B, A, C);
}

string output(bool x) {
    return x ? "yes" : "no";
}

int main () {
    Node A, B, C, D;
    while (cin >> A >> B >> C >> D) {
        bool flag = Judge(A, B, C, D) || Judge(A, C, B, D) || Judge(A, D, B, C) || Judge(A, B, D, C);
        cout << output(flag) << endl;
    }
    return 0;
}