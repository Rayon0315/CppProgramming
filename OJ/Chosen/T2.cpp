#include<iostream>
using namespace std;

bool isLeapYear(int x) {
    return (x % 100 != 0 && x % 4 == 0) || x % 400 == 0;
}

int LeapDays[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int NLeapDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void output(int y, int d, int days[]) {
    for (int i = 1; i <= 12; i++) {
        if (d > days[i]) {
            d -= days[i];
        } else {
            cout << y << '/' << i << '/' << d << endl;
            return;
        }
    }
}

int main() {
    int y, d;
    while (cin >> y >> d) {
        //cout << "---------isLeap:" << isLeapYear(y) << "--------" << endl;
        if (isLeapYear(y)) {
            output(y, d, LeapDays);
        } else {
            output(y, d, NLeapDays);
        }
    }
    return 0;
}