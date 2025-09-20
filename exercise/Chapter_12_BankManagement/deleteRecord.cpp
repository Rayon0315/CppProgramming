#include "BankAccount.h"

void deleteRecord(fstream &deleteFromBinary) {
    int accountNumber = getAccount("Enter account to delete:");
    
    deleteFromBinary.seekg((accountNumber - 1) * sizeof(BankAccount));

    BankAccount client;
    deleteFromBinary.read((char *)(&client), sizeof(BankAccount));
    
    if (client.getAccountNumber() != 0) {
        BankAccount blankAccount;
        
        deleteFromBinary.seekp((accountNumber - 1) * sizeof(BankAccount));

        deleteFromBinary.write((char *)(&blankAccount), sizeof(BankAccount));

        cout << "Account #" << accountNumber << "is deleted.\n";
    } else {
        cerr << "Account #" << accountNumber << "is empty.\n";
    }
}