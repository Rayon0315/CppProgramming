#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    char name[20];
    int age;
    char city[20];
};

int main() {
    string textFileName = "new_text_file.txt";
    string binaryFileName = "students.bin";

    ifstream textFile(textFileName);
    if (!textFile.is_open()) {
        cerr << "NOOOOOOO" << endl;
        return 1;
    }

    ofstream binaryFile(binaryFileName, ios_base::binary);
    if (!binaryFile.is_open()) {
        cerr << "NOOOOOOOO" << endl;
        return 1;
    }

    string titleLine;
    for (int i = 0; i < 3; i++)
        getline(textFile, titleLine);

    Student student;
    string line;
    while (getline(textFile, line)) {
        cout << line << endl;
        stringstream ss(line);
        string name;
        int age;
        string city;

        ss >> name;
        ss >> ws;

        ss >> age;
        ss >> ws;

        getline(ss, city);

        strncpy(student.name, name.c_str(), sizeof(student.name) - 1);
        student.name[sizeof(student.name) - 1] = '\0';

        student.age = age;

        strncpy(student.city, city.c_str(), sizeof(student.city) - 1);
        student.city[sizeof(student.city) - 1] = '\0';

        binaryFile.write((const char*)&student, sizeof(Student));
        if (!binaryFile) {
            cerr << "WRITE NOOOOOOO" << endl;
            return 1;
        }
    }

    textFile.close();
    binaryFile.close();

    cout << "已复制到二进制文件" << endl;
    return 0;
}