#include<iostream>
using namespace std;

int mat[25][25];

void matInit(int n) {
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        mat[i][j] = 1;
}

int main() {
    int n;
    while (cin >> n) {
        matInit(n);
        int sum = 0;
        for (int x = 2; x <= n; x++) {
            int i = x, j = 1;
            while (i <= n) {
                mat[i][j] = x;
                i++, j++;
                sum += x;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j == n) cout << mat[i][j];
                else cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << sum << endl;
    }
    return 0;
}