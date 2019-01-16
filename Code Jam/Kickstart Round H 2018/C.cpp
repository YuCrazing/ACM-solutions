#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const ll mod = 1e9 + 7;

ll fac[N], inv[N];

ll qmod(ll a, ll b) {
    ll r = 1;
    while(b) {
        if(b&1) r = r*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return r;
}

void init() {
    fac[0]=inv[0]=1;
    for(int i = 1; i < N; ++i) {
        fac[i] = fac[i-1]*i%mod;
        inv[i]=qmod(fac[i], mod-2);
    }
}

ll C(int n, int m) {
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}

int main () {

//    freopen("C-large-practice.in", "r", stdin);
//    freopen("C-large-practice.out", "w", stdout);

    init();

    int T, n, m;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca) {
        cin >> n >> m;
        ll ans = 0;
        int sgn = 1;
        for(int i = 0; i <= m; ++i) {
            ans = ((ans + sgn*C(m, i)*qmod(2, i)%mod*fac[2*n-i]%mod)%mod + mod)%mod;
            sgn *= -1;
        }
        cout << "Case #" << ca << ": " << ans << endl;
    }
    return 0;
}
