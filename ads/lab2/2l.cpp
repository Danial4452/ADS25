#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

int maxSubarraySum(Node* head) {
    int current_sum = head->val;
    int best_sum = head->val;

    head = head->next;
    while (head != NULL) {
        current_sum = max(head->val, current_sum + head->val);
        best_sum = max(best_sum, current_sum);
        head = head->next;
    }
    return best_sum;
}

int main() {
    int n;
    cin >> n;

    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* node = new Node(x);
        if (head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    cout << maxSubarraySum(head) << endl;
    return 0;
}