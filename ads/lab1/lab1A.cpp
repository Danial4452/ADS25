#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        deque<int> dq;
        for (int i = N; i >= 1; i--) {
            dq.push_front(i);
            for (int j = 0; j < i; j++) {
                int x = dq.back();
                dq.pop_back();
                dq.push_front(x);
            }
        }
        for (int i = 0; i < N; i++) {
            cout << dq[i] << " ";
        }
        cout << endl;
    }
    return 0;
}