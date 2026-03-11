#include <iostream>
using namespace std;

class Book {
private:
    string name;
    int price, number;

public:
    Book (string S, int P, int N)
        : name(S), price(P), number(N) {}

    void display() {
        cout << name << " " << price << " " << number << endl;
    }
    void borrow() {
        number --;
        cout << number << endl;
    }
    void restore() {
        number ++;
        cout << number << endl;
    }

    void showTotal() {
        cout << price * number << endl;
    }
};

int main() {
    string name;
    int price, number;

    while (cin >> name >> price >> number) {
        Book book(name, price, number);
        book.display();

        for (int _ = 0; _ < 5; _++) {
            char c; cin >> c;
            if (c == 'B') {
                book.borrow();
            } else if (c == 'R') {
                book.restore();
            } else if (c == 'C') {
                book.showTotal();
            }
        }
    }

    return 0;
}