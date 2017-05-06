#include<bits/stdc++.h>
using namespace std;

const int N = 102;
int dp[N][N][N], a[N][N], n, m, T;

int solve() {
    memset(dp, 0, sizeof(dp));
    dp[0][0][1] = a[0][0] + a[0][1];
    for(int k = 2; k < m; k++) dp[0][0][k] = dp[0][0][k - 1] + a[0][k];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m - 1; j++)
            for(int k = j + 1; k < m; k++)
                dp[i][j][k] = dp[i - 1][j][k] + a[i][j] + a[i][k];
        for(int j = 1; j < m - 1; j++)
            for(int k = j + 1; k < m; k++)
                dp[i][j][k] = max(dp[i][j][k],dp[i][j - 1][k] + a[i][j]);
        for(int j = 0; j < m - 2; j++) // j starts from 0.
            for(int k = j + 2; k < m; k++)
                dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + a[i][k]);
    }
    return dp[n - 1][m - 2][m - 1];
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
        printf("Case %d: %d\n", ca, solve());
    }
    return 0;
}
