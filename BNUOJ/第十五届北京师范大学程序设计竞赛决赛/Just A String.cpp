#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2003;

int _next[N], T;
string t, s;

void initKMP() {
    int l = s.size(), j = 0;
    _next[1] = _next[0] = 0;
    for(int i = 1; i < l; i++) {
        while(j > 0 && s[j] != s[i]) j = _next[j];
        if(s[j] == s[i]) j++;
        _next[i + 1] = j;
    }
}

ll KMP() {
    int lt = t.size(), ls = s.size(), j = 0;
    ll ans = 0;
    for(int i = 0; i < lt; i++) {
        while(j > 0 && t[i] != s[j]) j = _next[j];
        if(t[i] == s[j]) j++;
        ans ^= ll(i + 1 - j)*ll(j*j)*ll(ls - j);
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> t;
        int l = t.size();
        ll ans = 0;
        for(int i = 0; i < l; i++) {
            s = t.substr(i);
            initKMP();
            ans ^= KMP();
        }
        printf("%lld\n", ans);
    }
    return 0;
}
