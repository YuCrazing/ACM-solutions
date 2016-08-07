/*
    dp[i][j][k]: length is i, '(' is more j than ')', the most depth is k.(Don't consider '0')
*/

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 9;
const int N = 303;
ll C[N][N], dp[N][N][N];

void init() {
    for(int i = 0; i < N; i ++) C[i][0] = 1;
    for(int i = 1; i < N; i ++)
        for(int j = 1; j <= i; j ++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
}

int main() {

    init();
    int n, K;
    scanf("%d%d", &n, &K);

    dp[0][0][0] = 1;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j <= i; j ++)
            for(int k = 0; k <= i; k ++) {
                dp[i + 1][j + 1][max(j + 1, k)] = (dp[i][j][k] + dp[i + 1][j + 1][max(j + 1, k)]) % mod;
                if(j > 0) dp[i + 1][j - 1][k] = (dp[i][j][k] + dp[i + 1][j - 1][k]) % mod;
            }

    ll res = 0;
    for(int i = 0; i <= n; i ++) res = (res + dp[i][0][K] * C[n][i] % mod) % mod;

    printf("%I64d\n", res);
    return 0;
}
