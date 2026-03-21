#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string fileName = "new_text_file.txt";
    ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        cerr << "无法创建文件！" << endl;
        return 1;
    }

    outputFile << "创建文本文件" << endl;
    outputFile << "===========================" << endl;
    
    outputFile << left;
    outputFile << setw(10) << "Name" << setw(10) << "Age" << setw(10) << "City" << endl;
    outputFile << setw(10) << "Alice" << setw(10) << "20" << setw(10) << "New York" << endl;
    outputFile << setw(10) << "Bob" << setw(10) << "18" << setw(10) << "London" << endl;
    outputFile << setw(10) << "Cathy" << setw(10) << "22" << setw(10) << "Paris" << endl;

    outputFile.close();

    cout << "创建成功！" << endl;
    return 0;
}