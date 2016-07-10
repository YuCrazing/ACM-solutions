#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[111];
int dp[111][111];
int main(){
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        memset(dp, 0x3f, sizeof(dp));
        scanf("%s" ,s);
        int n = strlen(s);
        for(int j = 0; j < n; j ++){
            dp[j][j] = 0;
            for(int i = j - 1; i > -1; i --){
                if(s[i] == s[j]) {
                    if(i + 1 == j) dp[i][j] = 0;
                    else dp[i][j] = min(dp[i + 1][j - 1], dp[i][j]);
                }
                dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
                dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
            }
        }
        printf("Case %d: %d\n", cas, dp[0][n - 1]);
    }
    return 0;
}
