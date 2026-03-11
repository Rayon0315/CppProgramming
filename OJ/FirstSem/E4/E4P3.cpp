#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int x;
    Node *nxt;

    Node () : x(0), nxt(nullptr) {}
    Node (int X) : x(X), nxt(nullptr) {}
};

int main() {
    int n = 10;
    Node *head = new Node(INT_MIN);
    Node *ptr = head;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        Node *cur = new Node(x);
        ptr->nxt = cur;
        ptr = ptr->nxt;
    }

    int inp;
    while (cin >> inp) {
        ptr = head; //从头结点开始，满足插入数字极小的情况
        for (int i = 0; i <= 10; i++) {
            //cout << "----inp: " << inp << ", ptr->x: " << ptr->x << "----" << endl;
            if (ptr->nxt != nullptr) {
                if (inp >= ptr->x && inp <= ptr->nxt->x) {
                    Node *cur = new Node(inp);
                    cur->nxt = ptr->nxt;
                    ptr->nxt = cur;
                    break;
                }
            } else {
                if (inp >= ptr->x) {
                    Node *cur = new Node(inp);
                    cur->nxt = nullptr;
                    ptr->nxt = cur;
                    break;
                }
            }
            ptr = ptr->nxt;
        }

        ptr = head->nxt; //正常开始从head的下一个
        for (int i = 0; i < 10; i++) {
            if (i == 9) cout << ptr->x;
            else cout << ptr->x << " ";
            ptr = ptr->nxt;
        }
        cout << endl;
    }
    return 0;
}