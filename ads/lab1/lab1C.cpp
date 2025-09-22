#include <iostream>
#include <stack>
#include <string>
using namespace std;

string process(const string &s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            if (!st.empty()) st.pop();
        } else {
            st.push(s[i]);
        }
    }
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (process(s1) == process(s2)) cout << "Yes";
    else cout << "No";
    return 0;
}