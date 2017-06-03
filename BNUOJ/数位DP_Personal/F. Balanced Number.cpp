#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int L = 20;
int digs[L];
ll dp[L][2000][L];

void init() {
    memset(dp, -1, sizeof(dp));
}

ll dfs(int cur, int pre, int o, bool up) {
    if(!cur) {
        if(pre == 0) return 1; //
        return 0;
    }

    ll& dpp = dp[cur][pre][o];
    if(!up && dpp != -1) return dpp;

    int sup = up ? digs[cur] : 9;

    ll ans = 0;
    if(cur == o) {
        for(int i = 0; i <= sup; i++) ans += dfs(cur - 1, pre, o, up && i == digs[cur]);
    } else if(cur > o) {
        for(int i = 0; i <= sup; i++) ans += dfs(cur - 1, pre + i*(cur - o), o, up && i == digs[cur]);
    } else {
        for(int i = 0; i <= sup; i++) {
            int t = pre - (o - cur)*i;
            if(t >= 0) ans += dfs(cur - 1, t, o, up && i == digs[cur]);
        }
    }

    if(!up) dpp = ans;
    return ans;
}

ll calc(ll x) {
    if(x < 0) return 0;
    int l = 0;
    while(x) {
        digs[++l] = x % 10;
        x /= 10;
    }
    ll ans = 1; // 0
    for(int i = 1; i <= l; i++) {
        ans += dfs(l, 0, i, 1);
        ans--; // Remove extra 0s.
    }
    return ans;
}

int T;
ll x, y;
int main() {

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%lld%lld", &x, &y);
        printf("%lld\n",calc(y) - calc(x - 1));
    }
    return 0;
}
