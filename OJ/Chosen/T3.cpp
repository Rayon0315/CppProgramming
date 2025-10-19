#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        deque<string> cur;
        for (int i = 0; i < n; i++) {
            string inp; 
            cin >> inp;
            cur.push_back(inp);
        }
        
        vector<string> output;
        
        while (!cur.empty()) {
            if (cur.size() > 1) {
                string top = cur.front();
                cur.pop_front();
                cur.push_back(top);
            }
            
            if (!cur.empty()) {
                string next = cur.front();
                cur.pop_front();
                output.push_back(next);
            }
        }
        
        for (int i = 0; i < output.size(); i++) {
            cout << output[i];
            if (i < output.size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}