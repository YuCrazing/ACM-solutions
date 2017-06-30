#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, ans, t, x, T, dp[N][11];
int main() {
    while(scanf("%d", &n) != EOF && n) {
        T = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x, &t);
            dp[t][x]++;
            T = max(T, t);
        }

        for(int i = 0; i <= 10; i++) if(abs(i-5)>1) dp[1][i] = -1;

        for(int i = 2; i <= T; i++) {
            for(int j = 0; j <= 10; j++) {
                int maxx = dp[i-1][j];
                if(j>0) maxx = max(maxx, dp[i-1][j-1]);
                if(j<10) maxx = max(maxx, dp[i-1][j+1]);
                if(maxx == -1) dp[i][j] = -1;
                else dp[i][j] += maxx;
            }
        }

        ans = 0;
        for(int i = 0; i <= 10; i++) ans = max(ans, dp[T][i]);
        if(ans == -1) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
