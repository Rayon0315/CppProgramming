#include<iostream>
using namespace std;

int main() {
    long long code;
    int age;
    char gender;
    double moral;
    cout << "请输入编号、年龄、性别和德育分值:" << endl;
    cin >> code >> age >> gender >> moral;
    cout << code << "\t" << age << "\t" << gender << "\t" << moral << endl;
    return 0;
}