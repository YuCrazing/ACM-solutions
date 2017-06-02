#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 64;
ll dp[N], sum[N];
int T, n;

void init() {
    memset(dp, 0, sizeof(dp));
    sum[0] = dp[0] = dp[1] = 1;
    sum[1] = 2;
    for(int i = 2; i < N; i++) {
        dp[i] = sum[i - 2];
        sum[i] = dp[i] + sum[i - 1];
        printf("%d: %lld %lld\n", i, dp[i], sum[i] - 1);
    }
}

ll dfs(ll x, bool one) {
//    printf("%lld %d\n", x, one);

    if(!x) return one ? 1 : 0;

    int l = 0;
    ll xx = x;
    while(xx) {
        xx >>= 1;
        l++;
    }
    l--;


    ll ans = one ? sum[l] : sum[l] - 1;
    ll t = (1LL<<l);
    ll tt;
    if(l && (x & (1LL<<(l - 1)))) {
        ans += dfs((1LL<<(l - 1)) - 1, 1);
    } else ans += dfs(x - t, 1);
    return ans;
}

void print(ll x) {
    char s[66];
    int l = 0;
    while(x) {
        s[l++] = (x & 1) + '0';
        x >>= 1;
    }
    for(int i = l - 1; i >= 0; i--) printf(i == 0 ? "%c\n" : "%c", s[i]);
}

void BS() {
    ll l = 0, r = 1e18;
    while(l < r) {
        ll mid = (l + r) >> 1;
        if(dfs(mid, 0) >= n) r = mid;
        else l = mid + 1;
    }
    print(l);
}

int main() {

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);
        printf("Case %d: ", ca);
        BS();
    }

    return 0;
}
