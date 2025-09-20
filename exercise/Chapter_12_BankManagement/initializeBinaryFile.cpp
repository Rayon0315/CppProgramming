#include "BankAccount.h"
#include "GlobalVariable.h"

void initializeBinaryFile(fstream &binaryFileStream) {
    if (!binaryFileStream.is_open()) {
        binaryFileStream.open(fileName, ios_base::out | ios_base::binary);
        if (!binaryFileStream.is_open()) std::cerr << "Error: Failed to create file" << fileName << std::endl;
        binaryFileStream.close();

        binaryFileStream.open(fileName, ios_base::in | ios_base::out | ios_base::binary);
        if (!binaryFileStream.is_open()) std::cerr << "Error: Failed to reopen file" << fileName << std::endl;

        BankAccount blankAccount;
        for (int i = 0; i < 200; i++) binaryFileStream.write((char*)&blankAccount, sizeof(BankAccount));
        binaryFileStream.flush();
        binaryFileStream.seekg(0);
        cout << "Binary file initialized." << endl;
    } else {
        binaryFileStream.seekg(0);
        cout << "Binary file already open." << endl;
    }
}