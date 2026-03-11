#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int MAX_DEPTH = 1000;

struct Node {
    int x, y;
    int step;
    
    Node () : x(0), y(0), step(0) {}
    Node (int X, int Y) : x(X), y(Y) {}
    Node (int X, int Y, int S) : x(X), y(Y), step(S) {}

    bool operator == (Node A) {
        return x == A.x && y == A.y;
    }
    bool check(int m, int n) {
        return (x >= 0 && x <= m-1) && (y >= 0 && y <= n-1);
    }
    friend istream& operator >> (istream &in, Node &A) {
        in >> A.x >> A.y;
        A.step = 0;
        return in;
    }
    friend ostream& operator << (ostream &out, Node &A) {
        out << A.x << " " << A.y << " " << A.step;
        return out;
    }
};

int vis[505][505];
int mov[8][2] {
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        Node start, target;
        cin >> m >> n;
        cin >> start >> target;
        
        if (start == target) {
            cout << 0 << endl;
            continue;
        }
        
        queue<Node> Q1, Q2;
        memset(vis, 0, sizeof(vis));
        
        Q1.push(Node(start.x, start.y, 0));
        Q2.push(Node(target.x, target.y, 0));
        vis[start.x][start.y] = 1;
        vis[target.x][target.y] = 2;
        
        bool flag = false;
        int result = 0;
        
        while (!Q1.empty() && !Q2.empty()) {
            int size1 = Q1.size();
            for (int s = 0; s < size1; s++) {
                Node cur = Q1.front(); Q1.pop();
                
                if (cur.step > MAX_DEPTH) {
                    break;
                }
                
                for (int i = 0; i < 8; i++) {
                    Node nxt(cur.x + mov[i][0], cur.y + mov[i][1], cur.step + 1);
                    if (nxt.check(m, n)) {
                        if (vis[nxt.x][nxt.y] == 0) {
                            vis[nxt.x][nxt.y] = 1;
                            Q1.push(nxt);
                        } else if (vis[nxt.x][nxt.y] == 2) {
                            result = cur.step + nxt.step;
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) break;
            }
            if (flag) break;
            
            int size2 = Q2.size();
            for (int s = 0; s < size2; s++) {
                Node cur = Q2.front(); Q2.pop();
                
                if (cur.step > MAX_DEPTH) {
                    break;
                }
                
                for (int i = 0; i < 8; i++) {
                    Node nxt(cur.x + mov[i][0], cur.y + mov[i][1], cur.step + 1);
                    if (nxt.check(m, n)) {
                        if (vis[nxt.x][nxt.y] == 0) {
                            vis[nxt.x][nxt.y] = 2;
                            Q2.push(nxt);
                        } else if (vis[nxt.x][nxt.y] == 1) {
                            result = nxt.step + cur.step + 1;
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        
        if (flag) {
            cout << result << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}