#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int x) {
    for (int i = 2; i * i < x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

bool isForm(int x) {
    for (int i = 1; (2<<i) - 1 <= x; i++) {
        if ((2<<i) - 1 == x) return 1;
    }
    return 0;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        int flag = 0;
        vector<int> ans;
        for (int i = N; i <= M; i++) {
            if (isPrime(i) && isForm(i)) {
                ans.push_back(i);
                flag = 1;
            }
        }
        if (flag) {
            for (int i = 0; i < ans.size(); i++) {
                if (i == ans.size() - 1) cout << ans[i] << endl;
                else cout << ans[i] << " ";
            }
        } else {
            cout << -1 << endl;
        }
    }
}