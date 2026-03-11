#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(v[i][j], v[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0, k = n- 1; j <= k; j++, k--) {
                swap(v[i][j], v[i][k]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << v[i][j];
                if (j != n - 1) cout << " ";
            }
            cout << endl;
        }
    }
}