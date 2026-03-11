#include<iostream>
using namespace std;

struct Node {
    char x;
    Node *next;

    Node () : x('\0'), next(nullptr) {}
    Node (int X) : x(X), next(nullptr) {}
};
Node *head, *ptr, *frt;

int main() {
    string s;
    while (cin >> s) {
        head = new Node();
        ptr = head;
        for (char c : s) {
            Node *cur = new Node(c);
            ptr->next = cur;
            ptr = ptr->next;
//            cout << "-----" << ptr->x << "-----\n";
        }
        
        frt = nullptr;
        ptr = head->next;
        while (ptr != nullptr) {
            Node *tmp = ptr->next;
            ptr->next = frt;
            frt = ptr;
            ptr = tmp;
        }

        ptr = frt;
        while (ptr != nullptr) {
            cout << ptr->x;
            ptr = ptr->next;
        }
        cout << endl;
    }
    return 0;
}