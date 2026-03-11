#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> types = {0, 1, 2, 3};
double calc(double x, int op, double y) {
    switch (op) {
        case 0: return x + y;
        case 1: return x - y;
        case 2: return x * y;
        case 3:
            if (y != 0) return x / y;
            else return 1e15;
    }
    return 1e15;
}

bool equal(double x, double y) {
    return fabs(x - y) < 1e-6;
}

bool judge(vector<double> nums, vector<int> ops) {
    double res1 = calc(calc(calc(nums[0], ops[0], nums[1]), ops[1], nums[2]), ops[2], nums[3]);
    double res2 = calc(calc(nums[0], ops[0], nums[1]), ops[1], calc(nums[2], ops[2], nums[3]));
    return equal(res1, 24.0) || equal(res2, 24.0);
}

int main() {
    vector<double> nums(4, 0);
    while (cin >> nums[0] >> nums[1] >> nums[2] >> nums[3]) {
        sort(nums.begin(), nums.end());
        int flag = 0;
        do {
            for (int a : types)
            for (int b : types)
            for (int c : types) {
                vector<int> ops = {a, b, c};
                if (judge(nums, ops)) {
                    flag = 1;
                    break;
                }
            }
        } while (next_permutation(nums.begin(), nums.end()));
        cout << (flag ? "YES" : "NOT") << endl;
    }
}