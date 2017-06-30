#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;

const int N = 3000;
int n, m, dp[N][N];
char s[N], t[N];
int main() {
    while(scanf("%s%s", s+1, t+1) != EOF) {
        n = strlen(s+1);
        m = strlen(t+1);
        assert(n < N);
        assert(m < N);
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i] == t[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
