#include <bits/stdc++.h>
using namespace std;

const int N = 405;
const int INF = 0x3f3f3f3f;

int n, m;
int S[N], T[N], L[N], R[N];
int ts[N], cnt;
int num[N][N];
int pre[N][N], suf[N][N];
int f[N][N], ans[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> S[i] >> T[i];
        T[i] += S[i];
        ts[++cnt] = S[i];
        ts[++cnt] = T[i];
    }
    
    // 离散化
    sort(ts + 1, ts + cnt + 1);
    m = unique(ts + 1, ts + cnt + 1) - ts - 1;
    for (int i = 1; i <= n; i++) {
        L[i] = lower_bound(ts + 1, ts + m + 1, S[i]) - ts;
        R[i] = lower_bound(ts + 1, ts + m + 1, T[i]) - ts;
    }

    // 预处理 num[l][r]
    for (int l = 1; l <= m; l++) {
        for (int r = l + 1; r <= m; r++) {
            int c = 0;
            for (int i = 1; i <= n; i++) {
                if (L[i] >= l && R[i] <= r) {
                    c++;
                }
            }
            num[l][r] = c;
        }
    }

    // pre DP - 正确版本
    memset(pre, -0x3f, sizeof pre);
    pre[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            pre[i][j] = pre[i-1][j];  // 继承
        }
        for (int j = 0; j < i; j++) {
            int c = num[j+1][i];
            for (int k = 0; k <= n; k++) {
                if (pre[j][k] >= 0) {
                    // 区间 [j+1, i] 的活动给另一边
                    pre[i][k] = max(pre[i][k], pre[j][k] + c);
                    // 区间 [j+1, i] 的活动给这一边
                    if (k + c <= n) {
                        pre[i][k + c] = max(pre[i][k + c], pre[j][k]);
                    }
                }
            }
        }
    }

    // suf DP - 正确版本
    memset(suf, -0x3f, sizeof suf);
    suf[m+1][0] = 0;
    for (int i = m; i >= 1; i--) {
        for (int j = 0; j <= n; j++) {
            suf[i][j] = suf[i+1][j];  // 继承
        }
        for (int j = i + 1; j <= m + 1; j++) {
            int c = num[i][j-1];
            for (int k = 0; k <= n; k++) {
                if (suf[j][k] >= 0) {
                    // 区间 [i, j-1] 的活动给另一边
                    suf[i][k] = max(suf[i][k], suf[j][k] + c);
                    // 区间 [i, j-1] 的活动给这一边
                    if (k + c <= n) {
                        suf[i][k + c] = max(suf[i][k + c], suf[j][k]);
                    }
                }
            }
        }
    }

    // 第一问答案
    int res1 = 0;
    for (int j = 0; j <= n; j++) {
        res1 = max(res1, min(j, pre[m][j]));
    }
    cout << res1 << endl;

    // 计算 f[l][r] - 强制选择区间 [l, r] 内所有活动
    for (int l = 1; l <= m; l++) {
        for (int r = l; r <= m; r++) {
            int tot = num[l][r];
            // 利用单调性优化：当 x 增大时，y 应该减小
            for (int x = 0, y = n; x <= n; x++) {
                if (pre[l][x] < 0) continue;
                while (y >= 0) {
                    int val1 = min(x + tot + y, pre[l][x] + suf[r][y]);
                    int val2 = (y == 0 ? -1 : min(x + tot + y - 1, pre[l][x] + suf[r][y - 1]));
                    if (val2 >= val1) {
                        y--;
                    } else {
                        break;
                    }
                }
                if (y >= 0) {
                    f[l][r] = max(f[l][r], min(x + tot + y, pre[l][x] + suf[r][y]));
                }
            }
        }
    }

    // 第二问答案
    for (int i = 1; i <= n; i++) {
        ans[i] = 0;
        for (int l = 1; l <= L[i]; l++) {
            for (int r = R[i]; r <= m; r++) {
                ans[i] = max(ans[i], f[l][r]);
            }
        }
        cout << ans[i] << endl;
    }

    return 0;
}