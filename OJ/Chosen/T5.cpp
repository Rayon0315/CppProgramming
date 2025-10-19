#include<iostream>
#include<cctype>
#include<string>
using namespace std;

string solveMail(string s) {
    string out = "";
    int idxAt = s.find('@');
    if (idxAt == string::npos) return s;
    
    string name1 = s.substr(0, idxAt);
    string domain = s.substr(idxAt + 1);
    
    if (name1.length() >= 2) {
        out.push_back(tolower(name1[0]));
        out += "*****";
        out.push_back(tolower(name1[name1.length() - 1]));
    }
    
    out.push_back('@');
    
    for (char c : domain) {
        out.push_back(tolower(c));
    }
    
    return out;
}

string solveNumber(string s) {
    string dig = "";
    for (auto i : s) if (isdigit(i)) dig.push_back(i);
    
    if (dig.size() == 10) {
        return "***-***-" + dig.substr(6);
    } else {
        string pre = "";
        if (dig.size() == 11) pre = "+*-";
        else if (dig.size() == 12) pre = "+**-";
        else if (dig.size() == 13) pre = "+***-";
        return pre + "***-***-" + dig.substr(dig.size() - 4);
    }
}

string checkType(string s) {
    for (auto i : s) if (i == '@') return solveMail(s);
    return solveNumber(s);
}

int main() {
    int T; cin >> T;
    string trash; getline(cin, trash);
    while (T--) {
        string s;
        getline(cin, s);
        cout << checkType(s) << endl;
    }
    return 0;
}