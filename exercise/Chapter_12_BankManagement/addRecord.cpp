#include "BankAccount.h"

void addRecord(fstream &insertIntoBinary) {
    int accountNumber = getAccount("Enter a new account number:");

    insertIntoBinary.seekg((accountNumber - 1) * sizeof(BankAccount));

    BankAccount client;
    insertIntoBinary.read((char*)(&client), sizeof(BankAccount));

    if (client.getAccountNumber() == 0) {
        string accountHolder;
        double balance;
        
        cout << "Enter accountHoler, banlance: \n?";
        cin >> accountHolder;
        cin >> balance;
        
        client.setAccountNumber(accountNumber);
        client.setAccountHolder(accountHolder);
        client.setBalance(balance);

        insertIntoBinary.seekp((accountNumber - 1) * sizeof(BankAccount));
        insertIntoBinary.write((const char *)(&client), sizeof(BankAccount));
    } else {
        cerr << "Account #" << accountNumber << " already exists." << endl;
    }
}