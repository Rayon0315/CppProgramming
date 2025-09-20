#include "BankAccount.h"

int inputChoice() {
    cout << "---------------------------------------------------" << endl
         << "0 - Initialize a binary file" << endl
         << "1 - Add a new account" << endl
         << "2 - Delete an account" << endl
         << "3 - Update an account" << endl
         << "4 - Create a text file" << endl
         << "5 - Display the text file" << endl
         << "6 - End the program" << endl
         << "----------------------------------------------------" << endl
         << "Enter your choice from 0 to 6: " << endl;
         int menuChoice;
         cin >> menuChoice;
         return menuChoice;
}