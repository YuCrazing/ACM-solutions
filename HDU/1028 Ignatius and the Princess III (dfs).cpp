#include<bits/stdc++.h>
using namespace std;

const int N = 122;
int dp[N][N];

void init() {
    memset(dp, -1, sizeof(dp));
}

int dfs(int n, int m) {
    if(m > n) m = n;
    if(m == 1) return 1;
    if(dp[n][m] != -1) return dp[n][m];
    if(m == n) return dp[n][m] = 1 + dfs(n, m - 1);
    return dp[n][m] = dfs(n - m, m) + dfs(n, m - 1);
}

int main() {
    init();
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", dfs(n, n));
    }
    return 0;
}
