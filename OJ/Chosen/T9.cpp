#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        vector<int> cnt(26, 0);
        for (auto c : s) {
            if (isalpha(c)) {
                if (isupper(c)) c += 32;
                cnt[c - 'a']++;
            }
        }
        int id = 0, mx = -1;
        for (int i = 0; i < 26; i++) {
            if (mx < cnt[i]) {
                id = i;
                mx = cnt[i];
            }
        }
        cout << char(id + 'a') << " " << mx << endl;
    }
    return 0;
}