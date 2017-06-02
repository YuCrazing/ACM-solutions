/*
    Array parameter, memcpy size
*/

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const int L = 66;
int T, digs[L];
ll a, b, dp[L][32][32][32][2];

void init() {
    memset(dp, -1, sizeof(dp));
}

int getSta(bool bb[]) {
    int ans = 0;
    for(int i = 0; i < 5; i++) {
        if(bb[i] == true) ans += (1<<i);
    }
    return ans;
}

ll dfs(int cur, bool odd[], bool even[], bool zero, bool up, bool hasEven[]) {
    if(!cur) {
        if(zero) return 1;
        for(int i = 0; i < 5; i++) if(odd[i]) return 0;
        for(int i = 0; i < 5; i++) if(hasEven[i] && (!even[i])) return 0;
        return 1;
    }

    int oddSta = getSta(odd), evenSta = getSta(even), hasEvenSta = getSta(hasEven);

    ll& dpp = dp[cur][oddSta][evenSta][hasEvenSta][zero];

    if(!up && dpp != -1) return dpp;

    int sup = up ? digs[cur] : 9;

    ll ans = 0;
    for(int i = 1; i <= sup; i++) {
        bool todd[5], teven[5], thasEven[5];
        memcpy(todd, odd, 5);
        memcpy(teven, even, 5);
        memcpy(thasEven, hasEven, 5);
        if(i&1) {
            todd[i/2] = !todd[i/2];
        } else {
            teven[i/2] = !teven[i/2];
            thasEven[i/2] = true;
        }
        ans += dfs(cur - 1, todd, teven, 0, up && i == digs[cur], thasEven);
    }

    bool todd[5], teven[5], thasEven[5];
    memcpy(todd, odd, 5);
    memcpy(teven, even, 5);
    memcpy(thasEven, hasEven, 5);
    if(!zero) {
        teven[0] = !teven[0];
        thasEven[0] = true;
    }
    ans += dfs(cur - 1, todd, teven, zero, up && 0 == digs[cur], thasEven);

    if(!up) dpp = ans;
    return ans;
}

ll calc(ll x) {
    int l = 0;
    while(x) {
        digs[++l] = x % 10;
        x /= 10;
    }
    bool odd[5]= {false}, even[5]= {false}, hasEven[5]= {false};
    return dfs(l, odd, even, 1, 1, hasEven);
}
int main() {

    init();

    scanf("%d", &T);
    while(T--) {
        scanf("%llu%llu", &a, &b);
        printf("%llu\n", calc(b) - calc(a - 1));
    }
    return 0;
}
