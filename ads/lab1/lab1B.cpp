#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    if(!(cin >> n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> st; 
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.back() > a[i]) st.pop_back();
        ans[i] = st.empty() ? -1 : st.back();
        st.push_back(a[i]);
    }
    for(int i=0;i<n;i++){
        if(i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}