/*
    考虑每个元素a[i]对最终答案的贡献
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const ll mod = 1e9 + 7;

ll qmod(ll a, ll b) {
    ll r = 1;
    while(b) {
        if(b&1) r = r*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return r;
}

int sum[N], a[N], x[N], y[N], C, D, E1, E2, F, T, k, n;

void init() {
    sum[1] = k;
    for(int i = 2; i <= n; ++i) {
        sum[i] = i*(qmod(i, k)-1+mod)%mod*qmod(i-1, mod-2)%mod;
        sum[i] += sum[i-1];
        sum[i] %= mod;
    }
}


int main() {
    //freopen("C-large-practice.in", "r", stdin);
    //freopen("C-large-practice.out", "w", stdout);
    cin >> T;
    for(int ca = 1; ca <= T; ++ca) {
        cin >> n >> k >> x[1] >> y[1] >> C >> D >> E1 >> E2 >> F;
        for(int i = 2; i <= n; ++i) {
            x[i] = ((ll)C*x[i-1] + (ll)D*y[i-1] + E1) % F;
            y[i] = ((ll)D*x[i-1] + (ll)C*y[i-1] + E2) % F;
            a[i] = (x[i] + y[i]) % F;
        }
        a[1] = (x[1] + y[1]) % F; // !!

        init();

        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans = (ans + (ll)(n-i+1)*a[i]%mod*sum[i]%mod) % mod;
        }

        cerr << ca <<endl;
        cout << "Case #" << ca << ": " << ans << endl;
    }
    return 0;
}
