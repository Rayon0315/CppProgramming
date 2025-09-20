#include "BankAccount.h"

int getAccount(const char * const prompt) {
    int accountNumber;
    do {
        cout << prompt << " (1 - 200): ";
        cin >> accountNumber;
    } while (accountNumber < 1 || accountNumber > 200);
    return accountNumber;
}