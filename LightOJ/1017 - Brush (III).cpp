#include <cstdio>
#include <algorithm>
using namespace std;

int y[111], dp[111][111], nxt[111], pre[111];

int main(){
    int T, n, w, k, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d%d", &n, &w, &k);
        for(int i = 1; i <= n; i ++) scanf("%d%d", &x, &y[i]);
        sort(y + 1, y + n + 1);

        for(int i = n; i > 0; i --){
            int j;
            for(j = i - 1; j > -1; j --) if(y[i] - y[j] > w || j == 0) break;
            nxt[i] = j;
        }

        pre[n] = n;
        for(int i = n - 1; i > 0; i --){
            if(y[i] == y[i + 1]) pre[i] = pre[i + 1];
            else pre[i] = i;
        }

        for(int i = 0; i <= k; i ++) dp[0][i] = 0;
        for(int i = 1; i <= n; i ++){
            dp[i][0] = 0;
            for(int j = 1; j <= k; j ++)
                dp[i][j] = max(dp[nxt[i]][j - 1] + pre[i] - nxt[i], dp[i - 1][j]);
        }

        printf("Case %d: %d\n", cas, dp[n][k]);
    }
    return 0;
}
