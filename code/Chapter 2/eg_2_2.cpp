#include<iostream>
using namespace std;

int main() {
    int year = 2025;
    short month = 012; //八进制
    short day = 0x12; //十六进制
    short week = 0b1011; //二进制
    unsigned long long id = 440111111111111111ull;
    cout << "year = " << year << endl;
    cout << "month = " << month << endl;
    cout << "day = " << day << endl;
    cout << "week = " << week << endl;
    cout << "id = " << id << endl;
    return 0;
}