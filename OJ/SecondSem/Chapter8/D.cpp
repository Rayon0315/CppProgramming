#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string word;
        vector<string> vec;

        while (ss >> word) {
            vec.push_back(word);
        }

        for (int i = 0, j = vec.size() - 1; i <= j; i++, j--) {
            swap(vec[i], vec[j]);
        }

        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i != vec.size() - 1) cout << " ";
        }
        cout << endl;
    }
}