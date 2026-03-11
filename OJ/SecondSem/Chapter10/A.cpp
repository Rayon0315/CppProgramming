#include <iostream>
using namespace std;

const int pi = 3;

class Circle {
protected:
    int radius;

public:
    Circle (int R = 0) : radius(R) {}

    virtual int area() = 0;
    virtual int volume() = 0;
};

class Sphere : public Circle {
public:
    Sphere (int R = 0) : Circle(R) {}

    int area() {
        return 4 * pi * radius * radius;
    }
    int volume() {
        return 4 * radius * radius * radius; // pi 与 3 消掉
    }
};

class Column : public Circle {
protected:
    int height;

public:
    Column (int R = 0, int H = 0) : Circle(R), height(H) {}

    int area() {
        return 2 * pi * radius * radius + 2 * pi * radius * height;
    }
    int volume() {
        return pi * radius * radius * height;
    }
};

int main() {
    int R, H;
    while (cin >> R >> H) {
        Sphere sphere(R);
        Column column(R, H);

        cout << sphere.volume() << " " << sphere.area() << " "
             << column.volume() << " " << column.area() << endl;
    }
}