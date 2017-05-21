#include<bits/stdc++.h>
using namespace std;

const int N = 503;

int n, m, T, a[N][N], b[N][N], dp[N][N];

int solve() {
    memset(dp[0], 0, sizeof(dp[0]));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = max(dp[i - 1][j] + a[i][j], dp[i][j - 1] + b[i][j]);
    return dp[n][m];
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &m);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &b[i][j]);

        for(int i = 1; i <= n; i++) {
            a[i][0] = 0;
            for(int j = 1; j <= m; j++)
                a[i][j] += a[i][j - 1];
        }
        memset(b[0], 0, sizeof(b[0]));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++)
                b[i][j] += b[i - 1][j];
        }

        printf("Case %d: %d\n", ca, solve());

    }
    return 0;
}
