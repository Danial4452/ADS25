#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p) {
    if (p == 0) {
        node->next = head;
        return node;
    }
    Node* cur = head;
    for(int i = 1; i <= p - 1; i++) cur = cur->next;
    node->next = cur->next;
    cur->next = node;
    return head;
}

Node* remove(Node* head, int p) {
    if (p == 0) {
        Node* tmp = head->next;
        delete head;
        return tmp;
    }
    Node* cur = head;
    for (int i = 1; i <= p - 1; i++) cur = cur->next;
    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
    return head;
}

Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2) return head;
    Node* node;
    // Remove node at p1
    if (p1 == 0) {
        node = head;
        head = head->next;
    } else {
        Node* prev = head;
        for (int i = 1; i <= p1 - 1; i++) prev = prev->next;
        node = prev->next;
        prev->next = node->next;
    }
    // Insert node at p2 (after removal)
    if (p2 == 0) {
        node->next = head;
        head = node;
    } else {
        Node* cur = head;
        for (int i = 1; i <= p2 - 1; i++) cur = cur->next;
        node->next = cur->next;
        cur->next = node;
    }
    return head;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* cur = head;
    while(cur){
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

void print(Node* head) {
    if (!head) {
        cout << -1 << endl;
        return;
    }
    Node* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << " ";
        cur = cur->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x) {
    if (!head || !head->next) return head;
    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    x %= len;
    if (x == 0) return head;
    tail->next = head;
    Node* newTail = head;
    for (int i = 1; i < x; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    if (!head || !head->next) return head;
    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    x %= len;
    if (x == 0) return head;
    return cyclic_left(head, len - x);
}

 
int main(){
    Node* head = NULL;
    while (true){
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}