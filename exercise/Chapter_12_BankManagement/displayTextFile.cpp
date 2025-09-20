#include "BankAccount.h"
void displayTextFile(fstream &readFromBinary) {
    cout << left << setw(18) << "AccountNumber" << setw(16)
         << "AccountHolder" << right
         << setw(10) << "Balance" << endl;
    
        readFromBinary.clear();

        readFromBinary.seekg(0);

        BankAccount client;
        while (readFromBinary.read((char *)(&client), sizeof(BankAccount))) {
            if (client.getAccountNumber() != 0) cout << client;
        }
}