#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string fileName = "new_text_file.txt";
    
    ofstream outputFile(fileName, ios_base::out | ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "无法打开文件！" << endl;
        return 1;
    }

    outputFile << left;
    outputFile << setw(10) << "David" << setw(10) << "19" << setw(10) << "Boston" << endl;
    outputFile << setw(10) << "Jake" << setw(10) << "21" << setw(10) << "Toronto" << endl;

    cout << "记录已成功追加！" << endl;

    return 0;
}