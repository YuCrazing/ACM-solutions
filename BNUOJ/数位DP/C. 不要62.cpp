#include<bits/stdc++.h>
using namespace std;

const int L = 10;
int n, m, digs[L], len, dp[L][2];

void init() {
    memset(dp, -1, sizeof(dp));
}

/* six: there is a 6 before current position. */
int dfs(int cur, bool six, bool up) {

    if(!cur) {
        return 1;
    }

    if(!up && dp[cur][six] != -1) return dp[cur][six];

    int sup = up ? digs[cur] : 9;

    int ans = 0;

    for(int i = 0; i <= sup; i++)
        if(i != 4) {
            if(i == 2 && six) continue;
            ans += dfs(cur - 1, i == 6, i == digs[cur] & up);
        }

    if(!up) dp[cur][six] = ans;

    return ans;
}

int calc(int x) {
    len = 0;
    while(x) {
        digs[++len] = x % 10;
        x /= 10;
    }
    return dfs(len, 0, 1);
}

int main() {

    init();

    while(scanf("%d%d", &n, &m) != EOF) {
        if(!n && !m) break;
        printf("%d\n", calc(m) - calc(n - 1));
    }
    return 0;
}
