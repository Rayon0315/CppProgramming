#include<iostream>
#include<string>
using namespace std;

class Automobile {
protected:
    string make;
    string model;
    int year;

public:
    Automobile (const string& mk, const string& mdl, int yr)
    : make(mk), model(mdl), year(yr) {
        cout << "构造一个汽车对象" << endl;
    }
    ~Automobile () {
        cout << "析构一个汽车对象" << endl;
    }

    void displayInfor() const {
        cout << "制造厂商： " << make << ", 型号: " << model << ", 制造年份: " << year << endl;
    }
};

class ElectricCar: public Automobile {
protected:
    double batteryCapacity;

public:
    ElectricCar (const string &mk, const string &mdl, int yr, double battCap)
    : Automobile(mk, mdl, yr), batteryCapacity(battCap) {
        cout << "构造一个电动车对象" << endl;
    }
    ~ElectricCar () {
        cout << "析构一个电动车对象" << endl;
    }

    void displayInfor() const {
        cout << endl << "调用电动车的打印函数: " << endl;
        Automobile::displayInfor();
        cout << "型号: 电动车, 电池容量: " << batteryCapacity << "千瓦时" << endl;
    }
};

class GasolineCar: public virtual Automobile {
protected:
    double fuelCapacity;

public:
    GasolineCar (const string &mk, const string &mdl, int yr, double fuelCap)
    : Automobile(mk, mdl, yr), fuelCapacity(fuelCap) {
        cout << "构造一个燃油车对象" << endl;
    }
    ~GasolineCar () {
        cout << "析构一个燃油车对象" << endl;
    }

    void displayInfor() const {
        cout << endl << "调用燃油车的打印函数" << endl;
        Automobile::displayInfor();
        cout << "型号: 燃油车, 油箱容量: " << fuelCapacity << "升" << endl;
    }
};

class HybridCar: public ElectricCar, public GasolineCar {
private:
    double chargeEfficiency;

public:
    HybridCar (const string &mk, const string &mdl, int yr, double battCap, double fuelCap, double effi) 
    : Automobile(mk, mdl, yr), ElectricCar(mk, mdl, yr - 2, battCap), GasolineCar(mk, mdl, yr + 2, fuelCap), chargeEfficiency(effi) {
        cout << "构造一个混合动力车对象" << endl;
    }
    ~HybridCar () {
        cout << "析构一个混合动力车对象" << endl;
    }

    void displayInfor() const {
        cout << endl << "调用混合动力车的打印函数" << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
        ElectricCar::displayInfor();
        GasolineCar::displayInfor();
        cout << endl;
        cout << "型号: 混合动力车, 充电效率: " << chargeEfficiency << "%" << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
    }
};

int main() {
    HybridCar MyCar("SCUT", "A", 2021, 9.9, 10.1, 49.9);
    MyCar.displayInfor();
    return 0;
}