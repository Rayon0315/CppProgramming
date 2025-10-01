#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

const char ops[] = {'+', '-', '*', '/'};


double calculate(double a, char op, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 1e9;
    }
    return 0;
}

bool check(vector<double> nums, vector<char> operators) {
    double res1 = calculate(calculate(nums[0], operators[0], nums[1]), operators[1], calculate(nums[2], operators[2], nums[3]));
    double res2 = calculate(calculate(calculate(nums[0], operators[0], nums[1]), operators[1], nums[2]), operators[2], nums[3]);
    return fabs(res1 - 24) < 1e-6 || fabs(res2 - 24) < 1e-6;
}

int main() {
    vector<double> nums(4);
    while (cin >> nums[0] >> nums[1] >> nums[2] >> nums[3]) {
        sort(nums.begin(), nums.end());
        bool found = false;
        do {
                for (char op1 : ops)
                for (char op2 : ops)
                for (char op3 : ops) {
                    vector<char> opt = {op1, op2, op3};
                    if (check(nums, opt)) {
                        found = true;
                        break;
                    }
                }
        } while (!found && next_permutation(nums.begin(), nums.end()));
        cout << (found ? "YES" : "NOT") << endl;
    }
    return 0;
}