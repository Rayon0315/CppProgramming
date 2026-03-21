#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

int main() {
    string fileName = "new_text_file.txt";

    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cerr << "无法打开文件！" << endl;
        return 1;
    }

    string line;
    int maxAge = numeric_limits<int>::min();
    int minAge = numeric_limits<int>::max();
    int sumAge = 0;
    int count = 0;

    getline(inputFile, line);
    getline(inputFile, line);
    getline(inputFile, line);
    
    while (getline(inputFile, line)) {
        cout << line << endl;

        stringstream ss(line);
        string name, city;
        int age;

        ss >> name;
        ss >> age;
        getline(ss, city);

        if (age > maxAge) maxAge = age;
        if (age < minAge) minAge = age;
        sumAge += age;
        count++;
    }

    inputFile.close();

    double avgAge = (count > 0) ? static_cast<double>(sumAge) / count : 0;

    cout << "年龄最大值：" << maxAge << endl;
    cout << "年龄最小值：" << minAge << endl;
    cout << "平均年龄" << avgAge << endl;

    return 0;
}