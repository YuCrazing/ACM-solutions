#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int L = 64;
const int mod = 2520;
int T, digs[L], id[mod], tol;
ll dp[L][50][mod], a, b;

int lcm(int x, int y) {
    return x * y / __gcd(x, y);
}

void get(int cur, int pre) {
    if(cur > 9) {
        if(id[pre] == -1) id[pre] = tol++;
        return ;
    }
    get(cur + 1, lcm(pre, cur));
    get(cur + 1, pre);
}

void init() {
    memset(dp, -1, sizeof(dp));
    memset(id, -1, sizeof(id));
    tol = 0;
    get(1, 1);
}

ll dfs(int cur, int pre, int val, bool up) {
    if(!cur) {
        if(val%pre == 0) return 1;
        return 0;
    }

    ll& dpp = dp[cur][id[pre]][val];
    if(!up && dpp != -1) return dpp;

    int sup = up ? digs[cur] : 9;

    ll ans = 0;
    for(int i = 0; i <= sup; i++) {
        ans += dfs(cur - 1, i ? lcm(i, pre) : pre, (val*10 + i)%mod, up && i == digs[cur]);
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
    return dfs(l, 1, 0, 1);
}

int main() {

    init();
    scanf("%d", &T);
    while(T--) {
        scanf("%I64d%I64d", &a, &b);
        printf("%I64d\n", calc(b) - calc(a - 1));
    }
    return 0;
}
/*

1 9000000000000000000

*/
