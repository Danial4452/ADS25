#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int arr[100000]; 
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cin >> x;
    
    int l = 0, r = n - 1;
    bool found = false;
    
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) {
            found = true;
            break;
        } else if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    if (found) cout << "Yes";
    else cout << "No";
    
    return 0;
}