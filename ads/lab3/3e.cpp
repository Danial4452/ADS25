#include <iostream>
using namespace std;

const int N = 200000 + 123;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    int x1[N], x2[N], y1[N], y2[N];
    
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    
    int l = 0, r = 1000000000, cnt = 0;
    
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        cnt = 0;
        
        for(int i = 0; i < n; i++) {
            if(x2[i] <= mid && y2[i] <= mid) cnt++;
        }
        
        if(cnt >= k) r = mid;
        else l = mid;
    }
    cout << r << "\n";
    
    return 0;
}