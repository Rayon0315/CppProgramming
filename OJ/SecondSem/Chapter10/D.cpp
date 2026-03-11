#include <iostream>
using namespace std;

struct Node {
    int id;
    Node *next;

    Node (int I = 0) : id(I) {}
};

int main() {
    int n, m;
    while (cin >> n >> m) {
        Node *head = new Node(0);
        Node *ptr = head;
        for (int i = 1; i < n; i++) {
            Node *cur = new Node(i);
            ptr->next = cur;
            ptr = ptr->next;
            if (i == n-1) {
                ptr->next = head;
            }
        }

        int cnt = 0;
        Node *pre = ptr, *cur = head;
        while (pre->next != pre) {
            // 报数
            if (cnt == m - 1) {
                Node *tmp = cur;
                pre->next = cur->next;
                cur = cur->next;
                delete tmp;

                cnt = 0;
                continue;
            }

            // 未出列
            pre = pre->next;
            cur = cur->next;
            cnt ++;
        }
        cout << pre->id << endl;
    }
}