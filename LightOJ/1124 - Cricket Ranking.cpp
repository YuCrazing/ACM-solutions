#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int K = 11;
const int N = 1e6 + 11; //
const int mod = 100000007;

int sgn, n, k, T, l, r[K];
ll ans, f[N], inv[N];

inline void add(ll &a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
}

inline void mul(ll &a, ll b) {
    a *= b;
    if(a < 0) a += mod;
    else if(a >= mod) a %= mod;
}

ll qmod(ll a, int b) {
    ll res = 1;
    while(b) {
        if(b&1) mul(res, a);
        b >>= 1;
        mul(a, a);
    }
    return res;
}

void init() {
    f[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = f[i - 1];
        mul(f[i], i);
        inv[i] = qmod(f[i], mod - 2);
    }
}

ll c(int n, int m) {
    if(n < 0 || m > n) return 0;
    if(m == 0 || m == n) return 1;
    ll res = 1;
    mul(res, f[n]);
    mul(res, inv[m]);
    mul(res, inv[n - m]);
    return res;
}

//void dfs(ll val, int start, int num, int tol){
//    if(num == tol){
//        ll tmp = c(val - 1, k - 1);
//        mul(tmp, sgn);
//        add(ans, tmp);
//        return ;
//    }
//
//    for(int i = start; i <= k - tol + num; i++){
//        ll t = val - r[i];
//        if(t >= k) dfs(t, i + 1, num + 1, tol);
//    }
//}
//
//void solve1(){
//    ans = 0;
//    sgn = 1;
//    for(int i = 0; i <= k; i++){
//        dfs(n, 0, 0, i);
//        sgn *= -1;
//    }
//}

void solve2() {
    ans = 0;
    int t, ones;
    for(int s = 0; s < (1<<k); s++) {
        t = n;
        ones = 0;
        for(int i = 0; i < k; i++) {
            if((1<<i) & s) {
                ones ++;
                t -= r[i];
            }
        }
        if(ones & 1) sgn = -1;
        else sgn = 1;
        ll tmp = c(t - 1, k - 1);
        mul(tmp, sgn);
        add(ans, tmp); // Partition t into k parts.
//        printf("%d:%lld, one: %d, t: %d\n",s, sgn*c(t - 1, k - 1), ones, t);
    }
}

int main() {

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &k, &n);
        for(int i = 0; i < k; i++) {
            scanf("%d%d", &l, &r[i]);
            n -= l - 1; // n may increase.
            r[i] -= l - 1;
        }
        if(n < k) ans = 0;
        else {
            solve2();
        }
        printf("Case %d: %lld\n", ca, ans);
    }
    return 0;
}
