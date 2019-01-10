#include<bits/stdc++.h>
using namespace std;

const int N = 20;
const int INF = 0x3f3f3f3f;
int n, dp[1<<N][N], g[N][N];

void init() {
    for(int i = 0; i < (1<<n); ++i)
        for(int j = 0; j < n; ++j)
            dp[i][j] = -1;
}

int dfs(int s, int x) {
    int& dpp = dp[s][x];
    if(dpp != -1) return dpp;
    s ^= (1<<x);
    if(s==1) return dpp = g[0][x];
    dpp = INF;
    for(int i = 1; i < n; ++i) {
        if((1<<i) & s) {
            dpp = min(dpp, dfs(s, i) + g[i][x]);
        }
    }
    return dpp;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d", &g[i][j]);
    init();
    int ans = INF;
    for(int i = 1; i < n; ++i) {
        ans = min(ans, dfs((1<<n)-1, i) + g[i][0]);
    }
    printf("%d\n", ans);
    return 0;
}
