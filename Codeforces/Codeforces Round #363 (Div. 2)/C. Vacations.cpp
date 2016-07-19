#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int p[111], dp[111][4];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &p[i]);
    dp[1][0] = 1;
    if(p[1] & 1) dp[1][1] = 0;
    else dp[1][1] = -1;
    if(p[1] & 2) dp[1][2] = 0;
    else dp[1][2] = -1;
    for(int i = 2; i <= n; i ++){
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
        int res = INF;
        for(int j = 0; j < 3; j ++) if(dp[i - 1][j] != -1) res = min(res, dp[i - 1][j]);
        if(res != INF)dp[i][0] = res + 1;
        else dp[i][0] = 1;

        if(p[i] & 1){
            int res = INF;
            if(dp[i - 1][0] != -1) res = min(res, dp[i - 1][0]);
            if(dp[i - 1][2] != -1) res = min(res, dp[i - 1][2]);
            if(res != INF) dp[i][1] = res;
        }
        if(p[i] & 2){
            int res = INF;
            if(dp[i - 1][0] != -1) res = min(res, dp[i - 1][0]);
            if(dp[i - 1][1] != -1) res = min(res, dp[i - 1][1]);
            if(res != INF) dp[i][2] = res;
        }
    }
    int res = INF;
    for(int i = 0; i < 3; i ++) if(dp[n][i] != -1) res = min(res, dp[n][i]);

    printf("%d\n", res);
    return 0;
}
