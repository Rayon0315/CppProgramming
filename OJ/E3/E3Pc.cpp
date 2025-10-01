#include<iostream>
using namespace std;

int mat[1005][1005];

int main() {
    int n;
    while (cin >> n) {
        int x = 1, y = 1;
        int mx = -1, my = -1;
        bool flag = 0;
        for (int i = 1; i <= n; i++) {
            mat[x][y] = i;
            mx = max(mx, x);
            my = max(my, y);
            if (x == 1) x = y + 1, y = 1;
            else x -= 1, y += 1;
        }
        for (int i = 1; i <= mx; i++) {
            flag = 0;
            for (int j = 1; j <= my; j++) {
                if (mat[i][j]) {
                    if (j == 1) cout << mat[i][j];
                    else cout << " " << mat[i][j];
                    flag = 1;
                }
            }
            if (flag) cout << endl;
        }
    }
    return 0;
}