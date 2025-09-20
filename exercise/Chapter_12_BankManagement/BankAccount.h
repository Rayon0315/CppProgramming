#ifndef BANKACCOUNT_H

#define BANKACCOUNT_H
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    char accountHolder[20];
    double balance;

public:
    BankAccount (int = 0, const string & = "", double = 0.0);

    void setAccountNumber(int);
    int getAccountNumber() const;

    void setAccountHolder(const string &);
    string getAccountHolder() const;

    void setBalance(double);
    double getBalance() const;

    friend ostream& operator << (ostream&, const BankAccount& account);
};

void initializeBinaryFile(fstream&);
int inputChoice();
void addRecord(fstream&);
void deleteRecord(fstream&);
void updateRecord(fstream&);
void createTextFile(fstream&);
void displayTextFile(fstream&);
int getAccount(const char * const);

enum class RecordChoices { INITIALIZE, ADD, DELETE, UPDATE, CREATE_TEXT, DISPLAY_TEXT, END };

#endif