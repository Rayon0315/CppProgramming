#include<iostream>
#include<string>
#include<map>
using namespace std;

string cur;

void ADD() {
    string inp; int x;
    cin >> inp >> x;
    cur.insert(x+1, inp);
    cout << cur << endl;
}

void DEL() {
    int x, n;
    cin >> x >> n;
    cur.erase(x, n);
    cout << cur << endl;
}

void SER() {
    string tar;
    cin >> tar;
    cout << cur.find(tar) << endl;
}

void CHA() {
    string inp; int x;
    cin >> inp >> x;
    cur.replace(x, inp.size(), inp);
    cout << cur << endl;
}

int main() {
    cin >> cur;

    map<string, int> cast;
    cast["ADD"] = 0, cast["DEL"] = 1,
    cast["SER"] = 2, cast["CHA"] = 3;
    
    string opt;
    while (cin >> opt) {
        switch (cast[opt]) {
            case 0:
                ADD(); break;
            case 1:
                DEL(); break;
            case 2:
                SER(); break;
            case 3:
                CHA(); break;
            default:
                break;
        }
    }
    
    return 0;
}