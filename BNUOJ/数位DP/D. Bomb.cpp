#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int L = 66;
int digs[L], T;
ll dp[L][2], n;

void init() {
    memset(dp, -1, sizeof(dp));
}

ll dfs(int cur, bool four, bool up) {
    if(!cur) {
        return 1; //
    }

    if(!up && dp[cur][four] != -1) return dp[cur][four];

    int sup = up ? digs[cur] : 9;

    ll ans = 0;

    for(int i = 0; i <= sup; i++) {
        if(four && i == 9) continue;
        ans += dfs(cur - 1, i == 4, up && i == sup);
    }

    if(!up) dp[cur][four] = ans;
    return ans;
}

ll calc(ll x) {
    int l = 0;
    ll t = x;
    while(x) {
        digs[++l] = x % 10;
        x /= 10;
    }
    return t - dfs(l, 0, 1) + 1;
}
int main() {

    init();

    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &n);
        printf("%lld\n", calc(n));
    }
    return 0;
}
