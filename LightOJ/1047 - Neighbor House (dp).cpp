#include <cstdio>
#include <algorithm>
using namespace std;

int cost[22][3],dp[22][3], n, T;
int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < 3; j ++)
                scanf("%d", &cost[i][j]);

        for(int i = 0; i < 3; i ++) dp[0][i] = cost[0][i];

        for(int i = 1; i < n; i ++)
        for(int j = 0; j < 3; j ++){
            int minn = 0x3f3f3f3f;
            dp[i][j] = cost[i][j];
            for(int k = 0; k < 3; k ++) if(j != k) minn = min(minn, dp[i - 1][k]);
            dp[i][j] += minn;
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0; i < 3; i ++) ans = min(ans, dp[n - 1][i]);
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
