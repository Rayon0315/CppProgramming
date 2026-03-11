#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int offset = 16;
        for (int i = 0; i < s.size(); i += 16, offset += 16) {
            string cur = s.substr(i, 16);

            cout << setw(8) << setfill('0') << hex << nouppercase << offset << "  ";

            for (int x = 0; x < cur.size(); x++) {
                cout << hex << (int)cur[x] << " ";
            }
            cout << " ";

            cout << cur << endl;
        }
    }
}