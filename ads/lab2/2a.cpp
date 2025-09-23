#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

class Node {
public:
    int data;
    int index;
    Node* next;
    Node(int val, int idx) {
        data = val;
        index = idx;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int sz;

    LinkedList() {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    void push_back(int val) {
        Node* newNode = new Node(val, sz);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        sz++;
    }

    int find_nearest(int k) {
        int position = -1;
        int min_diff = INT_MAX;
        Node* current = head;

        while (current != NULL) {
            int diff = abs(current->data - k);
            if (diff < min_diff) {
                min_diff = diff;
                position = current->index;
            }
            current = current->next;
        }
        return position;
    }

    ~LinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList myList;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        myList.push_back(num);
    }

    int k;
    cin >> k;

    int position = myList.find_nearest(k);

    if (position != -1) {
        cout << position << endl;
    } else {
        cout << "No elements" << endl;
    }

    return 0;
}