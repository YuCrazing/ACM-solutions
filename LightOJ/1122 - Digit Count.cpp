#include<bits/stdc++.h>
using namespace std;

int d[11], dp[11][11];
int main() {
    int m, n, T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &m, &n);
        for(int i = 0; i < m; ++i) scanf("%d", &d[i]);

        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < m; ++i) dp[1][i] = 1;

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i==1&&d[j]==0) continue;
                for(int k = 0; k < m; ++k) {
                    if(abs(d[k] - d[j]) > 2) continue;
                    dp[i+1][k] += dp[i][j];
                }
            }
        }
        int ans=0;
        for(int i = 0; i < m; ++i) ans += dp[n][i];
        printf("Case %d: %d\n", ca, ans);

    }
    return 0;
}
/*

10
10 10
0 1 2 3 4 5 6 7 8 9
10 9
0 1 2 3 4 5 6 7 8 9
*/
