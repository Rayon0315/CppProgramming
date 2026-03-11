#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Unit {
    string text;
    int val;

    Unit() {
        text = "";
        val = 0;
    }

    void transformFromText() {
        val = 0;
        int pow = 1;
        for (int i = text.size() - 1; i >= 0; i--) {
            val += (text[i] == '1') * pow;
            pow <<= 1;
        }
    }
};

bool cmp(Unit a, Unit b) {
    return a.val < b.val;
}

int main() {
    string s, t;
    while (cin >> s >> t) {
        vector<Unit> vec;
        for (int i = 0; i < s.size(); i += 8) {
            Unit x;
            x.text = s.substr(i, 8);
            x.transformFromText();
            vec.push_back(x);
        }
        for (int i = 0; i < t.size(); i += 8) {
            Unit x;
            x.text = t.substr(i, 8);
            x.transformFromText();
            vec.push_back(x);
        }

        sort(vec.begin(), vec.end(), cmp);

        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i].text;
        }
        cout << endl;
    }
}