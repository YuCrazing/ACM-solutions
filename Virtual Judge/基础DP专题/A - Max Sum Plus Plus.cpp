/*
    C++: long long will get TLE.

    dp[i][j]:（i<=j）将前j个数分为i组，且必须选第j个数的答案。
    若第j个数与之前的数在同一组，则答案为：dp[i][j-1]+a[j]。
    若从第j个数开始新的一组，则答案为：max(dp[i-1][j-1])+a[j]。
*/

#include<cstdio>
#include<cassert>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
const int INF = 1e9;
int n, m, a[N], dp[2][N];
int main() {
    while(scanf("%d%d", &m, &n) != EOF) {

        assert(m <= n);

        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

        int cur = 1, pre = 0;
        dp[cur][0] = dp[pre][0] = 0;
        for(int i = 1; i <= n; i++) dp[cur][i] = 0;
        for(int i = 1; i <= m; i++) {
            swap(cur, pre);
            int p = 0;
            for(int j = i; j <= n; j++) {
                if(!p || (dp[pre][p] < dp[pre][j-1])) p = j-1; //!!
                if(i == j) dp[cur][j] = dp[pre][j-1]+a[j];
                else dp[cur][j] = max(dp[cur][j-1]+a[j], dp[pre][p]+a[j]);
            }
        }

        int ans = -INF;
        for(int i = 1; i <= n; i++) if(i >= m) ans = max(ans, dp[cur][i]);
        printf("%d\n", ans);
    }
    return 0;
}
