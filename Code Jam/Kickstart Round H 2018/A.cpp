#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll qmod(ll a, ll b) {
    ll r = 1;
    while(b) {
        if(b&1) r = r*a;
        a *= a;
        b >>= 1;
    }
    return r;
}

set<string> st;
string str;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.out", "w", stdout);

    int T, n, p;
    ll ans;

    cin >> T;
    for(int ca = 1; ca <= T; ++ca) {

        cin >> n >> p;

        ans = qmod(2, n);
        st.clear();

        for(int i = 0; i < p; ++i) {
            cin >> str;
            st.insert(str);
        }

        for(auto s1 : st) {
            bool prefix = true;
            for(auto s2 : st) {
                if(s1 == s2) continue;
                bool same = true;
                for(int k = 0; k < min(s1.size(), s2.size()); ++k) {
                    if(s1[k] != s2[k]) {
                        same = false;
                        break;
                    }
                }
                if(same && s2.size() < s1.size()) {
                    prefix = false;
                    break;
                }
            }
            if(prefix) {
                ans -= qmod(2, n-s1.size());
            }
        }
        cout << "Case #" << ca << ": " << ans << endl;
    }
    return 0;
}
