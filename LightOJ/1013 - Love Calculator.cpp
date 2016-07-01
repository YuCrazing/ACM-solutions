#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

char s[2][33];
int lcs[33][33];
ll dp[33][33];
int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%s%s", s[0], s[1]);

        memset(lcs, 0, sizeof(lcs));
        memset(dp, 0, sizeof(dp));
        int l1 = strlen(s[0]), l2 = strlen(s[1]);

        for(int i = 1; i <= l1; i ++)
            for(int j = 1; j <= l2; j ++)
                if(s[0][i - 1] == s[1][j - 1]) lcs[i][j] += lcs[i - 1][j - 1] + 1;
                else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);

        dp[0][0] = 1;
        for(int i = 1; i <= l1; i ++) dp[i][0] = 1;
        for(int i = 1; i <= l2; i ++) dp[0][i] = 1;
        for(int i = 1; i <= l1; i ++)
            for(int j = 1; j <= l2; j ++)
                if(s[0][i - 1] == s[1][j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else{
                    if(lcs[i][j - 1] == lcs[i][j]) dp[i][j] += dp[i][j - 1];
                    if(lcs[i - 1][j] == lcs[i][j]) dp[i][j] += dp[i - 1][j];
                }
        printf("Case %d: %d %lld\n", cas, l1 + l2 - lcs[l1][l2], dp[l1][l2]);
    }
    return 0;
}
