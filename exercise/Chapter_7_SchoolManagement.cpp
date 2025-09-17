#include<iostream>
#include<string>
using namespace std;

class Date {
private:
    int year, month, day;
    bool isLeapYear(int y);
    bool isValidDay(int m, int d);
public:
    Date(int y, int m, int d);
    void setDate(int y, int m, int d);
    void printDate() const;
};

bool Date::isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
bool Date::isValidDay(int m, int d) {
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > daysInMonth[m]) return false;
    if (m == 2 && d == 29 && !isLeapYear(year)) return false;
    return true;
}

Date::Date(int y, int m, int d) {
    setDate(y, m, d);
}
void Date::setDate(int y, int m, int d) {
    if (isValidDay(m, d)) {
        year = y;
        month = m;
        day = d;
    } else {
        cout << "输入日期无效,将重置日期为2000.1.1" << endl;
        year = 2000;
        month = 1;
        day = 1;
    }
}

void Date::printDate() const {
    cout << year << "-" << month << "-" << day << endl;
}

class Address {
private:
    string street;
    string city;
    string zipCode;

public:
    Address() : street(""), city(""), zipCode("") {}
    Address (const string &st, const string &ct, const string &zc) : street(st), city(ct), zipCode(zc) {}

    void setStreet(const string &st);
    void setCity(const string &ct);
    void setZipCode(const string &zc);
    string getStreet() const;
    string getCity() const;
    string getZipCode() const;
    void printAddress() const;
};

void Address::setStreet(const string &st) { street = st; }
void Address::setCity(const string &ct) { city = ct; }
void Address::setZipCode(const string &zc) { zipCode = zc; }

string Address::getStreet() const { return street; }
string Address::getCity() const { return city; }
string Address::getZipCode() const { return zipCode; }

void Address::printAddress() const {
    cout << "   Street: " << street << endl;
    cout << "   City: " << city << endl;
    cout << "   ZIP Code: " << zipCode << endl;
}

class Student {
private:
    string name;
    Date birthDate;
    Address homeAddress;
    string major;
    const string idCard;
    static int studentCount;

public:
    Student(const string &ne, const Date &bd, const Address &ha, const string &mj, const string &ic);
    ~Student();
    Student(const Student&);
    void printStudentInfo() const;
    static int getStudentCount();
    friend class School;
};

int Student::studentCount = 0;

Student::Student(const string &ne, const Date &bd, const Address &ha, const string &mj, const string &ic)
    : name(ne), birthDate(bd), homeAddress(ha), major(mj), idCard(ic) {}

Student::Student(const Student& other)
    : name(other.name), birthDate(other.birthDate), homeAddress(other.homeAddress), major(other.major), idCard(other.idCard) {
    studentCount ++;
}

Student::~Student() {
    studentCount --;
}

void Student::printStudentInfo() const {
    cout << "Name: " << name << endl; 
    cout << "Birth Date: ";
    birthDate.printDate();
    cout << "Address: " << endl;
    homeAddress.printAddress();
    cout << "Major: " << major << endl;
    cout << "ID Card: " << idCard << endl;
}

int Student::getStudentCount() {
    return studentCount;
}

class School {
private:
    int MAX_STUDENTS;
    Student ** students;
    int studentNumber;
public:
    School(int m);
    ~School();
    bool enrollStudent(Student& student);
    bool withdrawStudent(const string& idCard);
    int getStudentNumber() const;
};

School::School(int m) {
    MAX_STUDENTS = m;
    students = new Student * [MAX_STUDENTS];
    studentNumber = 0;
}

School::~School() {
    delete[] students;
}

bool School::enrollStudent(Student& student) {
    if(studentNumber >= MAX_STUDENTS) {
        cout << "人数已满,注册失败!" << endl;
        return false;
    }
    students[studentNumber] = &student;
    studentNumber ++;
    cout << "学生注册：" << student.name << endl;
    return true;
}

bool School::withdrawStudent(const string &idCard) {
    for (int i = 0; i < studentNumber; i ++) {
        if (students[i]->idCard == idCard) {
            for (int j = i; j < studentNumber - 1; j ++) {
                students[j] = students[j + 1];
            }
            studentNumber --;
            cout << "学籍已注销："<< idCard << endl;
            return true;
        }
    }
    cout << "指定学生号：" << idCard << "未找到,注销失败！" << endl;
    return false;
}

int School::getStudentNumber() const {
    return studentNumber;
}


int main() {
    Student A("Ray", Date(2077, 5, 12), Address("XGW", "GZ", "11111"), "Computer Science", "xxxxxx");
    Student B("Josh", Date(2077, 4, 30), Address("XGW", "GZ", "11111"), "Computer Science", "yyyyyy");
    A.printStudentInfo();
    cout << "--------------\n";
    School scut(1);
    scut.enrollStudent(A);
    scut.enrollStudent(B);
    cout << "--------------\n";
    scut.withdrawStudent("xxxxxx");
    scut.withdrawStudent("yyyyyy");
    return 0;
}