#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int main() {
    int T;
    while (cin >> T) {
        while (T--) {
            int n; cin >> n;
            vector<int> nums;
            for (int i = 0; i < n; i++) {
                int x; cin >> x;
                nums.push_back(x);
            }
            sort(nums.begin(), nums.end());
            int mn = INT_MAX;
            for (int i = 0; i < n-1; i++) {
                if (nums[i] != nums[i+1]) {
                    mn = min(mn, nums[i+1] - nums[i]);
                }
            }
            vector<int> ans;
            for (int i = 0; i < n-1; i++) {
                if (nums[i+1] - nums[i] == mn) {
                    ans.push_back(nums[i]);
                    ans.push_back(nums[i+1]);
                }
            }
            for (int i = 0; i < ans.size(); i++) {
                if (i == ans.size() - 1) cout << ans[i] << endl;
                else cout << ans[i] << " ";
            }
        }
    }
}