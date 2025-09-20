#include "BankAccount.h"

ostream& operator << (ostream& output, const BankAccount& account) {
    output << left << setw(18) << account.getAccountNumber()
                   << setw(16) << account.getAccountHolder()
                   << setw(10) << setprecision(2) << right << fixed
                   << showpoint << account.getBalance() << endl;
    return output;
}

BankAccount::BankAccount (int accountNumberValue, const string &accountHolderValue, double balanceValue)
: accountNumber(accountNumberValue), balance(balanceValue) {
    setAccountHolder(accountHolderValue);
}

void BankAccount::setAccountNumber(int accountNumberValue) { accountNumber = accountNumberValue; }
int BankAccount::getAccountNumber() const { return accountNumber; }

void BankAccount::setAccountHolder(const string &accountHolderString) {
    int length = accountHolderString.size();
    length = (length < 20 ? length : 19);
    accountHolderString.copy(accountHolder, length);
    accountHolder[length] = '\0';    
}
string BankAccount::getAccountHolder() const { return accountHolder; }

void BankAccount::setBalance(double balanceValue) { balance = balanceValue; }
double BankAccount::getBalance() const {return balance; }