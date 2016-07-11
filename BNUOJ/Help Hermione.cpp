#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXK = 2555;

ll qmod(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll f[MAXK], fac[MAXK], inv[MAXK];
int main() {
    fac[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < MAXK; i ++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = qmod(fac[i], MOD - 2);
    }
    int T;
    ll n, k;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%lld%lld", &n, &k);
        f[0] = 0;
        for(int i = 1; i  <= k + 2;  i++) f[i] = (f[i - 1] + qmod(i, k)) % MOD;
        ll xp = 1;
        ll res = 0;
        if(n <= k + 2) {
            for(int i = 1; i <= n; i ++) res = (res + qmod(i, k)) % MOD;
        } else {
            for(int i = 1; i <= k + 2; i ++) xp = xp * (n - i) % MOD;

            ll  sgn;
            for(int i = 1; i <= k + 2; i ++) {
                if((k + 2 - i) & 1) sgn = -1;
                else sgn = 1;
                res = (res + sgn * xp * qmod(n - i, MOD - 2) % MOD * inv[i - 1] % MOD * inv[k + 2 - i] % MOD * f[i] % MOD );
                res += MOD;
                res %= MOD;
            }
        }

        res =(qmod((n * (n + 1) / 2) % MOD, k) - res) % MOD;
        res += MOD;
        res %= MOD;
        printf("%lld\n", res);

    }

    return 0;
}
