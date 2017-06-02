#include<bits/stdc++.h>
#define TL tuple<ll, ll, ll>
#define mt make_tuple
using namespace std;
typedef long long ll;

const int L = 20;
const ll mod = 1e9 + 7;

int digs[L];
ll dp[L][7][7][3], p[L], inv6;

ll qmod(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}

void init() {
    inv6 = qmod(6, mod - 2);
    p[0] = 1;
    for(int i = 1; i < L; i++) p[i] = p[i-1]*10%mod;
    memset(dp, -1, sizeof(dp));
}

TL dfs(int cur, int sum, int m, bool up) {
    if(!cur) {
        if(sum && m) return mt(1, 0, 0);
        return mt(0, 0, 0);
    }

    ll &dpp0 = dp[cur][sum][m][0];
    ll &dpp1 = dp[cur][sum][m][1];
    ll &dpp2 = dp[cur][sum][m][2];

    if(!up && dpp0 != -1) {
        return mt(dpp0, dpp1, dpp2);
    }

    int sup = up ? digs[cur] : 9;

    TL ans = mt(0, 0, 0), t;

    ll& a0 = get<0>(ans);
    ll& a1 = get<1>(ans);
    ll& a2 = get<2>(ans);

    ll& b0 = get<0>(t);
    ll& b1 = get<1>(t);
    ll& b2 = get<2>(t);

    for(int i = 0; i <= sup; i++)
        if(i != 7) {
            t = dfs(cur - 1, (sum+i)%7, (m*10+i)%7, up && i == digs[cur]);

            a0 = (a0 + b0) % mod;
            a1 = ((a1 + b0*i%mod*p[cur-1]%mod) % mod + b1) % mod;
            a2 = (((a2 + b0*i%mod*p[cur-1]%mod*i%mod*p[cur-1]%mod) % mod + 2*i*p[cur-1]%mod*b1%mod) % mod + b2) % mod;
        }

    if(!up) {
        dp[cur][sum][m][0] = a0;
        dp[cur][sum][m][1] = a1;
        dp[cur][sum][m][2] = a2;
    }

    return ans;
}

ll calc(ll x) {
    int l = 0;
    while(x) {
        digs[++l] = x % 10;
        x /= 10;
    }

    TL res = dfs(l, 0, 0, 1);
    return get<2>(res);
}

int T;
ll l, r;
int main() {

    init();

    scanf("%d", &T);
    while(T--) {
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", (calc(r) - calc(l - 1) + mod)%mod);
    }
    return 0;
}
