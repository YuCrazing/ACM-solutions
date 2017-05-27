#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 2;
const ll mod = 1000000007;
int n, k, T, f[N], inv[N];

ll qmod(ll a, int b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void init() {
    f[0] = inv[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = (ll)f[i - 1] * (ll)i % mod;
//        inv[i] = qmod(f[i], mod - 2); // Waste time.
    }
}

int main() {

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &k);
        k--;
        n += k;
        printf("Case %d: %d\n", ca, (ll)f[n] * qmod(f[k], mod - 2) % mod * qmod(f[n - k], mod - 2) % mod);
    }
    return 0;
}
