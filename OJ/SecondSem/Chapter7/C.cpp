#include <iostream>
using namespace std;

class Student {
private:
    int score;
    static int total;
    static int count;

public:
    void scoretotalcount(int s) {
        score = s;
        total += s;
        count ++;
    }

    static int sum() {
        return total;
    }

    static int average() {
        return total / count;
    }

};

int Student::total = 0;
int Student::count = 0;

int main() {
    int data[5];
    while (cin >> data[0]) {
        Student stu0;
        stu0.scoretotalcount(data[0]);

        for (int i = 1; i < 5; i++) {
            Student stu;
            cin >> data[i];
            stu.scoretotalcount(data[i]);
        }

        cout << Student::sum() << " " << Student::average() << endl;
    }

    return 0;
}