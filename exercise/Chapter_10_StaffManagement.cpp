#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee (const string &nameInput, int idInput) : name(nameInput), id(idInput) {}
    virtual ~Employee () {}
    virtual double calculateSalary() const = 0;

    void printInfor() const {
        cout << "证件号: " << id << ", 姓名: " << name << endl;
    }
};

class HourlyWorker: public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyWorker (const string &nameInput, int idInput, double hourlyRateInput, int hoursWorkedInput)
    : Employee(nameInput, idInput), hourlyRate(hourlyRateInput), hoursWorked(hoursWorkedInput) {}

    double calculateSalary() const {
        return hourlyRate * hoursWorked;
    }
};

class SalariedWorker: public Employee {
private:
    double annualSalary;

public:
    SalariedWorker (const string &nameInput, int idInput, double annualSalaryInput)
    : Employee(nameInput, idInput), annualSalary(annualSalaryInput) {}

    double calculateSalary() const {
        return annualSalary / 12.0;
    }
};

class PayrollSystem {
private:
    vector<Employee*> employees;

public:
    ~PayrollSystem() {
        int n = employees.size();
        for (int i = 0; i < n; i++) {
            delete employees[i];
        }
    }

    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }
    void processPayroll() {
        int n = employees.size();
        for (int i = 0; i < n; i++) {
            employees[i] -> printInfor();
            cout << "月薪: " << employees[i] -> calculateSalary() << endl;
        }
    }
};


int main() {
    PayrollSystem sys;
    sys.addEmployee(new HourlyWorker("Alex", 100001, 20.0, 160));
    sys.addEmployee(new SalariedWorker("Ben", 100002, 60000));
    sys.processPayroll();
    return 0;
}