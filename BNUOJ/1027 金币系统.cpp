#include<bits/stdc++.h>
using namespace std;

int m, n, T, v[30];
long long dp[10111];
int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &m, &n);
        for(int i = 0; i < m; i++) scanf("%d", &v[i]);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < m; i++)
            for(int j = v[i]; j <= n; j++)
                dp[j] += dp[j - v[i]];
        printf("%lld\n", dp[n]);
    }
    return 0;
}
