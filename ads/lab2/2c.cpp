#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

int main(){
    int x,n;
    cin >> n;

    Node *head = NULL, *tail = NULL;
    for(int i = 1; i <=n; i++){
        cin >> x;
        Node* node = new Node(x);
        if(head==NULL){
            head = tail = node;
        }
        else{
            if(i%2!=0){
                tail->next = node;
                tail = node;

            }
        }
    }

    Node *cur = head;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }


    return 0;
}

