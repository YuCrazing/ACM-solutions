#include<bits/stdc++.h>
using namespace std;

int n, dp[11][2][2][13], digs[11];

void init() {
    memset(dp, -1, sizeof(dp));
}

int dfs(int cur, bool one, bool has, int k, bool up) {
    if(!cur) {
        if(has && k == 0) return 1;
        return 0;
    }

    int& dpp = dp[cur][one][has][k];

    if(!up && dpp != -1) return dpp;

    int sup = up ? digs[cur] : 9;

    int ans = 0;
    for(int i = 0; i <= sup; i++) {
        ans += dfs(cur - 1, i == 1, has || (one && i == 3), (k*10 + i)%13, up && i == digs[cur]);
    }

    if(!up) dpp = ans;
    return ans;
}

int calc(int x) {
    int l = 0;
    while(x) {
        digs[++l] = x%10;
        x /= 10;
    }
    return dfs(l, 0, 0, 0, 1);
}

int main() {

    init();

    while(scanf("%d", &n) != EOF) {
        printf("%d\n", calc(n));
    }
    return 0;
}
