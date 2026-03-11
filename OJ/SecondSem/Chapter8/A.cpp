#include <iostream>
using namespace std;

class String {
private:
    string s;

    friend String operator + (const String &a, const String &b);

public:
    String (string S = "") : s(S) {}

    void output() { cout << s << endl; }
};

String operator + (const String &a, const String &b) {
    return String(a.s + b.s);
}

int main() {
    string s, t;
    while (cin >> s >> t) {
        String a(s), b(t);
        (a + b).output();
    }
    return 0;
}