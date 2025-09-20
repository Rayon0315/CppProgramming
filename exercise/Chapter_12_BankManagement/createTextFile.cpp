#include "BankAccount.h"

void createTextFile(fstream &readFromBinary) {
    ofstream outTextStream("customerAccount.txt", ios_base::out);

    if (!outTextStream.is_open()) {
        cerr << "The text file could not be created." << endl;
        exit(EXIT_FAILURE);
    }

    outTextStream << left << setw(18) << "AccountNumber" << setw(16)
                  << "AccountHolder" << right
                  << setw(10) << "Balance" << endl;
    
    readFromBinary.clear();

    readFromBinary.seekg(0);

    BankAccount client;
    while (readFromBinary.read((char *)(&client), sizeof(BankAccount))) {
        if (client.getAccountNumber() != 0) outTextStream << client;
    }

    cout << "The text file has been created!" << endl;
}