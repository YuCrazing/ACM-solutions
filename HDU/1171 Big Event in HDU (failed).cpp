#include<cstdio>
#include<cstring>
using namespace std;

const int N = 51;
const int V = 51;
const int M = 201;
const int MAX = N * V * M / 20;
int dp[MAX][M], v[N], m[N], n;

void solve() {

    int sum = 0;
    for(int i = 1; i <= n; i++) sum += v[i] * m[i];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= m[1]; i++) {
        int t = i * v[1];
        for(int j = t; j < MAX; j += t)
            for(int k = i; k < M; k++)
                dp[j][k] = 1;
    }

    for(int i = 2; i <= n; i++) {

        for(int j = v[i]; j < MAX; j++) {
            dp[j][0] = dp[j][m[i - 1]];
            for(int k = 1; k < M; k++) {
                if(k > m[i]) dp[j][k] = dp[j][k - 1];
                else dp[j][k] = dp[j][m[i - 1]] +  dp[j - v[i]][k - 1];
            }
        }

//        for(int j = 0; j <= sum; j ++)
//            for(int k = 0; k <= m[i]; k++)
//                printf("dp[%d][%d] = %d\n", j, k, dp[j][k]);
    }

    int mid = (sum + 1) / 2;
    for(int i = mid; i <= sum; i++) {
        if(dp[i][m[n]]) {
            printf("%d %d\n", i, sum - i);
            break;
        }
    }
}
int main() {
    while(scanf("%d", &n) && n >= 0) {
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &v[i], &m[i]);
        }
        solve();
    }
    return 0;
}
