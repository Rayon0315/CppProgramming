#include <iostream>
using namespace std;

class Staff {
protected:
    string name;
    static int basicSalary;

public:
    Staff (string S = "") : name(S) {}
    virtual void countSalary() = 0;
};
int Staff::basicSalary = 2000;

class Teacher : public Staff {
protected:
    int level;
    int classHour;
    static int subsidy[4];

public:
    Teacher (string S, int L, int C) : Staff(S), level(L), classHour(C) {}

    void countSalary() {
        int salary = basicSalary + subsidy[level] * classHour;
        cout << name << " " << salary << endl;
    }
};
int Teacher::subsidy[4] = { 0, 50, 30, 20 };

class AdministrativeStaff : public Staff {
protected:
    int jobSalary;

public:
    AdministrativeStaff (string S, int J) : Staff(S), jobSalary(J) {}

    void countSalary() {
        int salary = basicSalary + jobSalary;
        cout << name << " " << salary << endl;
    }
};

class LabPersonnel : public Staff {
protected:
    static int subsidy;
    int workDays;

public:
    LabPersonnel(string S, int W) : Staff(S), workDays(W) {}

    void countSalary() {
        int salary = basicSalary + subsidy * workDays;
        cout << name << " " << salary << endl;
    }
};
int LabPersonnel::subsidy = 20;

int main() {
    string name;
    int level, classHour;
    int jobSalary;
    int workDays;

    while (cin >> name >> level >> classHour) {
        Teacher teacher(name, level, classHour);
        teacher.countSalary();

        cin >> name >> jobSalary;
        AdministrativeStaff administrativeStaff(name, jobSalary);
        administrativeStaff.countSalary();

        cin >> name >> workDays;
        LabPersonnel labPersonnel(name, workDays);
        labPersonnel.countSalary();
    }
}