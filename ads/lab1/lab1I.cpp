#include <iostream>
#include <deque>
#include <stack>
#include <string>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    string input;
    cin >> input;
    
  
    deque<char> votes;
    stack<int> should_d_k;  
    stack<int> should_d_s;  
    
  
    for (char c : input) {
        votes.push_back(c);
    }
    
  
    int count_s = 0, count_k = 0;
    for (char c : input) {
        if (c == 'S') count_s++;
        else if (c == 'K') count_k++;
    }
    
  
    while (!votes.empty()) {
        char cur = votes.front();
        votes.pop_front();
        
        if (cur == 'K') {
            if (should_d_k.empty()) {
                votes.push_back(cur);
                should_d_s.push(1);
            } else {
                should_d_k.pop();
                count_k--;
            }
        } else if (cur == 'S') {
            if (should_d_s.empty()) {
                votes.push_back(cur);
                should_d_k.push(1);
            } else {
                should_d_s.pop();
                count_s--;
            }
        }
        
   
        if (count_k == 0) {
            cout << "SAKAYANAGI" << endl;
            break;
        }
        if (count_s == 0) {
            cout << "KATSURAGI" << endl;
            break;
        }
    }
    
    return 0;
}