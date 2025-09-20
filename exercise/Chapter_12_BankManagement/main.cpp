#include <iostream>
#include "BankAccount.h"
#include "GlobalVariable.h"

int main() {
    fstream inOutFileStream(fileName);
    RecordChoices enumChoice;
    int intChoice = inputChoice();

    while ((enumChoice = static_cast<RecordChoices>(intChoice)) != RecordChoices::END) {
        switch (enumChoice)
        {
        case RecordChoices::INITIALIZE:
            initializeBinaryFile(inOutFileStream);
            break;
        case RecordChoices::ADD:
            addRecord(inOutFileStream);
            break;
        case RecordChoices::DELETE:
            deleteRecord(inOutFileStream);
            break;
        case RecordChoices::UPDATE:
            updateRecord(inOutFileStream);
            break;
        case RecordChoices::CREATE_TEXT:
            createTextFile(inOutFileStream);
            break;
        case RecordChoices::DISPLAY_TEXT:
            displayTextFile(inOutFileStream);
            break;
        default:
            cerr << "Incorrect choice" << endl;
            break;
        }
        inOutFileStream.clear();
        intChoice = inputChoice();
    }
    return 0;
}