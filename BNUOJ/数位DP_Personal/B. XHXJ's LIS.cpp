#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int L = 20;
const int S = 1<<10;
int k, T, digs[L], len[S], go[S][10];
ll dp[L][S][2][11];

void init() {
    memset(dp, -1, sizeof(dp));
    for(int s = 0; s < S; s++) {

        len[s] = __builtin_popcount(s);

        for(int i = 0; i < 10; i++) {
            if(s&(1<<i)) {
                go[s][i] = s;
            } else {
                // Find minimum value which is larger than i.
                bool ok = false;
                for(int j = i + 1; j < 10; j++) {
                    if(s&(1<<j)) {
                        go[s][i] = s ^ (1<<i) ^ (1<<j);
                        ok = true;
                        break;
                    }
                }
                if(!ok) go[s][i] = s ^ (1<<i);
            }
        }

    }
}

ll dfs(int cur, int sta, bool zero, bool up) {
    if(!cur) {
        if(len[sta] == k) return 1;
        return 0;
    }

    ll& dpp = dp[cur][sta][zero][k];
    if(!up && dpp != -1) return dpp;

    int sup = up ? digs[cur] : 9;

    ll ans = 0;
    for(int i = 1; i <= sup; i++) {
        ans += dfs(cur - 1, go[sta][i], 0, up && i == digs[cur]);
    }

    if(zero) {
        ans += dfs(cur - 1, sta, 1, up && 0 == digs[cur]);
    } else {
        ans += dfs(cur - 1, go[sta][0], 0, up && 0 == digs[cur]);
    }

    if(!up) dpp = ans;
    return ans;
}

ll calc(ll x) {
    int l = 0;
    while(x) {
        digs[++l] = x % 10;
        x /= 10;
    }
    return dfs(l, 0, 1, 1);
}

ll l, r;
int main() {

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%I64d%I64d%d", &l, &r, &k);
        printf("Case #%d: %I64d\n", ca, calc(r) - calc(l - 1));
    }
    return 0;
}
