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
    Teacher (string S = "", int L = 0, int C = 0) : Staff(S), level(L), classHour(C) {}
    Teacher (const Teacher& oth) {
        level = oth.level;
        classHour = oth.classHour;
    }

    void countSalary() {
        int salary = basicSalary + subsidy[level] * classHour;
        cout << name << " " << salary << endl;
    }

    int getSalary() {
        return basicSalary + subsidy[level] * classHour;
    }
};
int Teacher::subsidy[4] = { 0, 50, 30, 20 };

class TeacherNode {
public:
    Teacher teacher;
    TeacherNode *next;

    TeacherNode (Teacher T = Teacher()) : teacher(T), next(nullptr) {}
};

int main() {
    string name; int level, classHour;

    while (cin >> name >> level >> classHour) {
        TeacherNode *head = new TeacherNode(Teacher(name, level, classHour));
        TeacherNode *ptr = head;
        for (int i = 0; i < 3; i++) {
            cin >> name >> level >> classHour;
            TeacherNode *cur = new TeacherNode(Teacher(name, level, classHour));
            ptr->next = cur;
            ptr = ptr->next;
        }

        int totalSalary = 0, maxSalary = head->teacher.getSalary(), minSalary = head->teacher.getSalary();
        ptr = head;
        while (ptr) {
            int salary = ptr->teacher.getSalary();
            totalSalary += salary;
            maxSalary = max(maxSalary, salary);
            minSalary = min(minSalary, salary);
            ptr = ptr->next;
        }

        cout << totalSalary << endl
             << totalSalary / 4 << endl
             << maxSalary << endl
             << minSalary << endl;
    }

    return 0;
}