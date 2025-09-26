#include <iostream>
using namespace std;

struct Node {
    string val;
    Node* next;
    Node* prev;
    Node(string x) : val(x), next(NULL), prev(NULL) {}
};

int main() {
    int n, cnt = 0;
    cin >> n;

    Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        Node* node = new Node(s);

        if (head == NULL) {
            head = tail = node;
            cnt++;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
            if (node->val != node->prev->val) cnt++;
        }
    }

    cout << "All in all: " << cnt << "\nStudents:\n";

    Node* cur = tail;
    while (cur != NULL) {
        cout << cur->val << "\n";
        while (cur->prev != NULL && cur->val == cur->prev->val) {
            cur = cur->prev;
        }
        cur = cur->prev;
    }

    return 0;
}