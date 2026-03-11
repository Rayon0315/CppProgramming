#include <iostream>
using namespace std;

bool isdigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 && isdigit(s[i])) {
                cout << '*' << s[i];
                if (i < s.size() - 1 && !isdigit(s[i+1]))
                    cout << '*';
            } else if (i == s.size() - 1 && isdigit(s[i])) {
                if (i > 0 && !isdigit(s[i-1]))
                    cout << '*';
                cout << s[i] << '*';
            } else if (i > 0 && !isdigit(s[i-1]) && isdigit(s[i])) {
                cout << '*' << s[i];
            } else if (i < s.size()-1 && isdigit(s[i]) && !isdigit(s[i+1])) {
                cout << s[i] << '*';
            } else {
                cout << s[i];
            }
        }
        cout << endl;
    }
}