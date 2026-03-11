#include <iostream>
using namespace std;

class Rectangle {
protected:
    int length, width;

public:
    Rectangle(int L, int W)
        : length(L), width(W) {}
    
    int S() {
        return length * width;
    }
};

class Rectangular : public Rectangle {
protected:
    int height;

public:
    Rectangular(int L, int W, int H)
        : Rectangle(L, W), height(H) {}

    int V() {
        return S() * height;
    }
};

int main() {
    int L, W, H;
    while (cin >> L >> W) {
        Rectangle rectangle(L, W);
        cout << rectangle.S() << endl;

        cin >> L >> W >> H;
        Rectangular rectangular(L, W, H);
        cout << rectangular.V() << endl;
    }
}