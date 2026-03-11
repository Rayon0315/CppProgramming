#include <iostream>
using namespace std;

class Employee {
protected:
    string id;
    string name;
    int basicSalary;

public:
    Employee(string I, string N, double B)
        : id(I), name(N), basicSalary(B) {}

    void output() {
        cout << name << " "
             << id << " "
             << basicSalary << endl;
    }
};

class Salesman : public Employee {
protected:
    int sales;
    static double commerate;

public:
    Salesman(string I, string N, double B, double S)
        : Employee(I, N, B), sales(S) {}
    
    void output() {
        double salary = basicSalary + sales * commerate;

        cout << name << " "
             << id << " "
             << salary << endl;
    }
};

class Salesmanager : public Salesman {
protected:
    int jobSalary;

public:
    Salesmanager(string I, string N, double B, double S, double J)
        : Salesman(I, N, B, S), jobSalary(J) {}
    
    void output() {
        double salary = basicSalary + jobSalary + sales * commerate;

        cout << name << " "
             << id << " "
             << salary << endl;
    }
};

double Salesman::commerate = 5. / 1000;
int basicSalary = 2000, jobSalary = 3000;

int main() {
    string id, name;
    int sales;
    while (cin >> id >> name) {
        Employee employee(id, name, basicSalary);
        employee.output();

        cin >> id >> name >> sales;
        Salesman salesman(id, name, basicSalary, sales);
        salesman.output();

        cin >> id >> name >> sales;
        Salesmanager salesmanager(id, name, basicSalary, sales, jobSalary);
        salesmanager.output();
    }

    return 0;
}