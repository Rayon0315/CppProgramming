#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student {
    char name[20];
    int age;
    char city[20];
};

int main() {
    string binaryFileName = "students.bin";

    ifstream binaryFile(binaryFileName, ios_base::binary);
    if (!binaryFile.is_open()) {
        cerr << "NOOOOOOOOOO" << endl;
        return 1;
    }

    Student student;
    cout << left;
    cout << setw(10) << "name" << setw(10) << "age" << setw(10) << "city" << endl;
    while (binaryFile.read((char*)&student, sizeof(Student))) {
        cout << setw(10) << student.name
             << setw(10) << student.age
             << setw(10) << student.city << endl;
    }

    binaryFile.close();
    cout << "记录已成功读取" << endl;
    return 0;
}