#include "BankAccount.h"

void updateRecord(fstream &updateBinary) {
    int accountNumber = getAccount("Enter account to update");

    updateBinary.seekg((accountNumber - 1) * sizeof(BankAccount));

    BankAccount client;
    updateBinary.read((char *)(&client), sizeof(BankAccount));

    if (client.getAccountNumber() != 0) {
        cout << client;

        cout << "\nEnter Deposit(+) or Withdraw(-):";
        double transaction;
        cin >> transaction;

        double oldBalance = client.getBalance();
        client.setBalance(oldBalance + transaction);
        cout << client;

        updateBinary.seekp((accountNumber - 1) * sizeof(BankAccount));

        updateBinary.write(reinterpret_cast<const char*>(&client), sizeof(BankAccount));
    } else {
        cerr << "Account #" << accountNumber << " has no information." << endl;
    }
}