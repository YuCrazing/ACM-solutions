#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

char s[66];
ll dp[66][66]; //
int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%s", s);
        int n = strlen(s);
        memset(dp, 0, sizeof(dp));
        for(int j = 0; j < n; j ++) {
            dp[j][j] = 1;
            for(int i = j - 1; i >= 0; i --) {
                dp[i][j] = 0;
                if(s[i] == s[j]) dp[i][j] += 1 + dp[i + 1][j - 1];   //
                dp[i][j] += dp[i + 1][j];
                dp[i][j] += dp[i][j - 1];
                dp[i][j] -= dp[i + 1][j - 1]; //
            }
        }
        printf("Case %d: %lld\n", cas, dp[0][n - 1]);
    }
    return 0;
}
