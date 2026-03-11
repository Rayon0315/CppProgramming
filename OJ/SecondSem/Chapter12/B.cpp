#include <iostream>
using namespace std;

int main() {
    // freopen("out.txt", "w", stdout);

    string line;
    while (getline(cin, line)) {
        if (line.size() >= 2) {
            if (line[0] == '/' && line[1] == '/') continue;

            if (line[0] == '/' && line[1] == '*') {
                while (getline(cin, line)) {
                    int len = line.size();
                    if (line[len-2] == '*' && line[len-1] == '/') break;
                }
                continue;
            }

            int len = line.size();
            for (int i = 0; i < len; i++) {
                if (i < len - 1 && line[i] == '/' && line[i + 1] == '/') {
                    break;
                }
                cout << line[i];
            }
            cout << endl;
        } else {
            cout << line << endl;
        }
    }
    return 0;
}