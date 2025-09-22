#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main(){
    char ch;
    deque<int> dq;
    int num;

    while(cin >>  ch){
        if(ch == '!'){
            break;
        }
        if(ch == '+'){
            cin >> num;
            dq.push_front(num);
        }
        else if (ch == '-') {
            cin >> num;
            dq.push_back(num);
        }
        else if (ch == '*') {
                if (dq.empty()) {
                cout << "error" << endl;
            }
            else if (dq.size() == 1) {
               
                int result = dq.front() + dq.front();
                cout << result << endl;
                dq.pop_front();
            }

                else {
                    int result = dq.front() + dq.back(); 
                    cout << result << endl;
                    dq.pop_front(); 
                    dq.pop_back(); 
            }
        }    
    }
    return 0;
}