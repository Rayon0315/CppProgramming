#include <iostream>
using namespace std;

class Box {
private:
    int length, width, height;

public:
    Box(int L = 0, int W = 0, int H = 0)
        : length(L), width(W), height(H) {}
    
    void setBox(int L, int W, int H) {
        length = L;
        width = W;
        height = H;
    }

    void volume() {
        cout << length * width * height << endl;
    }
};

int main() {
    int l, w, h;
    while (cin >> l >> w >> h) {
        Box A;
        A.setBox(l, w, h);
        A.volume();
    }

    return 0;
}