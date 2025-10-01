#include<iostream>
#include<vector>
using namespace std;

vector<int> primeList;

bool judgePrime(int x) {
    for (int i = 2; i * i < x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
void generatePrime() {
    for (int i = 2; i <= 135; i++) {
        if (judgePrime(i)) primeList.push_back(i);
    }
}

int main() {
    generatePrime();
    
    int n;
    while (cin >> n) {
        for (int x : primeList) {
            if (n == 0) break;
            while (n % x == 0) {
                cout << " " << x;
                n /= x;
            }
        }
        cout << endl;
    }
    return 0;
}