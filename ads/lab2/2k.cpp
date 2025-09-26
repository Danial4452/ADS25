#include <iostream>
#include <map>
using namespace std;

struct Node {
    char val;
    Node* next;
    Node(char x) : val(x), next(NULL) {}
};

struct Queue {
    Node* head;
    Node* tail;

    Queue() {
        head = tail = NULL;
    }

    bool empty() {
        return head == NULL;
    }

    void push(char x) {
        Node* node = new Node(x);
        if (tail == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void pop() {
        if (head == NULL) return;
        Node* tmp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete tmp;
    }

    char front() {
        return head->val;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        map<char,int> freq;
        Queue q;

        for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            freq[c]++;
            q.push(c);

            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }

            if (q.empty()) cout << -1 << " ";
            else cout << q.front() << " ";
        }
        cout << endl;
    }
    return 0;
}