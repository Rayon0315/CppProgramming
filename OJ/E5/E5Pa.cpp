#include<iostream>
#include<climits>
using namespace std;

struct Student{
    string name;
    int score;

    Student () : name(""), score(0) {}
    Student (string N, int S) : name(N), score(S) {}
};

int main() {
    string name;
    int score;
    Student cur("default", INT_MIN);
    while (cin >> name >> score) {
        Student A(name, score);
        if (A.score > cur.score) cur = A;
    }
    cout << cur.name;
    return 0;
}