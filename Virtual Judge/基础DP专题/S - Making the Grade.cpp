/*
    结论1：最终数组中的数字一定都是原数组中出现过的数字。

    由结论1得到动态规划状态：
    dp[i][j]表示前i个数不减（增）且第i个数为mp[j]的最小花费。mp[j]表示原数组中第j小的数。
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 2022;
const ll INF = 9e18;
int n, m, a[N], b[N], mp[N];
ll dp[N][N];
int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        m = unique(b + 1, b + n + 1) - (b + 1);
        for(int i = 1; i <= n; i++) {
            int t = lower_bound(b + 1, b + m + 1, a[i]) - (b + 1) + 1;
            mp[t] = a[i];
        }

        // 不减
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            int p = 0;
            for(int j = 1; j <= m; j++) {
                if(!p || dp[i-1][p]>dp[i-1][j]) p = j;
                dp[i][j] = dp[i-1][p]+abs(a[i]-mp[j]);
            }
        }

        ll ans = INF;
        for(int i = 1; i <= m; i++) ans = min(ans, dp[n][i]);

        // 不增
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            int p = 0;
            for(int j = m; j > 0; j--) {
                if(!p || dp[i-1][p]>dp[i-1][j]) p = j;
                dp[i][j] = dp[i-1][p]+abs(a[i]-mp[j]);
            }
        }

        for(int i = 1; i <= m; i++) ans = min(ans, dp[n][i]);
        printf("%lld\n", ans);
    }
    return 0;
}

/*

5
0 1000000000 0 1000000000 0

*/
