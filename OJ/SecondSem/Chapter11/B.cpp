#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node *next;

    Node (T D) : data(D), next(nullptr) {}
};

int main() {
    int x;
    while (cin >> x) {
        Node<int> *head = new Node(x);
        Node<int> *ptr = head;
        for (int i = 0; i < 5; i++) {
            cin >> x;
            Node<int> *cur = new Node(x);
            ptr->next = cur;
            ptr = ptr->next;
        }

        ptr = head;
        while (ptr) {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
        cout << endl;
    }
}