#include <cstdio>
#include <algorithm>
using namespace std;

int dp[111][111], sum[111], a[111];
int main(){
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        sum[0] = 0;
        for(int i = 1; i <= n; i ++) sum[i] = a[i] + sum[i - 1];
        for(int j = 1; j <= n; j ++){
            dp[j][j] = a[j];
            for(int i = j - 1; i > 0; i --){
                dp[i][j] = sum[j] - sum[i - 1]; // Take all
                for(int pos = i; pos <= j; pos ++){
                    if(pos + 1 <= j) dp[i][j] = max(dp[i][j], sum[pos] - sum[i - 1] - dp[pos + 1][j]);
                    if(i <= pos - 1) dp[i][j] = max(dp[i][j], sum[j] - sum[pos - 1] - dp[i][pos - 1]);
                }
            }
        }
        printf("Case %d: %d\n", cas, dp[1][n]);
    }
    return 0;
}
