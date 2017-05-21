#include<bits/stdc++.h>
using namespace std;

const int N = 503;

int n, m, T, a[N][N], b[N][N], dp[N][N];

int solve() {
    for(int i = 0; i <= m; i++) dp[1][i] = a[1][i] + b[1][i+1];
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            int maxx = 0;
            for(int k = 0; k <= j; k++) maxx = max(maxx, dp[i - 1][k]);
            dp[i][j] = maxx + a[i][j] + b[i][j + 1] ;
        }
    }
    int ans = 0;
    for(int i = 0; i <= m; i++) ans = max(ans, dp[n][i]);
    return ans;
}
int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &m);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
            a[i][0] = 0;
            for(int j = 1; j <= m; j++) a[i][j] += a[i][j-1];
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++)
                scanf("%d", &b[i][j]);
            b[i][m+1] = 0;
            for(int j = m; j >= 1; j--) b[i][j] += b[i][j+1];
        }

        printf("Case %d: %d\n", ca, solve());
    }
    return 0;
}
