#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> st;
int main() {
    cin >> s;
    int n = s.size();
    if(n%2==1) {
        st.push(s[0]);
        s = s.substr(1, n-1);
        --n;
    }

    for(int i = 0; 2*i < n; ++i) {
        st.push(s[n-1-i]);
        st.push(s[i]);
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;

    return 0;
}

