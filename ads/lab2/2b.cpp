#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

class Node {
public:
    string data;
    int index;
    Node* next;
    Node(string val, int idx) {
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

    void push_back(string val) {
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

    void rotate(int k) {
        if (head == NULL || k <= 0 || k >= sz) return;

        Node* curr = head;
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }

        Node* newHead = curr->next;
        Node* newTail = curr;
        tail->next = head;
        head = newHead;
        tail = newTail;
        tail->next = NULL;
    }
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << " ";
            temp = temp->next;
        }
        cout << endl;
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
    int n,k;
    cin >> n >> k;
    

    LinkedList myList;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        myList.push_back(s);
    }

    myList.rotate(k);
    myList.print();
    

    

    return 0;
}