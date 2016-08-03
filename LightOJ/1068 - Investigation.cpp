#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

ll dp[10][85][85], p10[10];

void init(int K) {

    memset(dp, 0, sizeof(dp));

    dp[0][0][0] = 1;

    for(ll i = 0; i < 9; i ++)
        for(ll j = 0; j < K; j ++)
            for(ll k = 0; k < K; k ++)
                for(ll x = 0; x < 10; x ++)
                    dp[i + 1][(j + x * p10[i] % K) % K][(k + x) % K] += dp[i][j][k];

}

int digit[10], len;

ll calc(int x, int K) {

    len = 0;
    while(x) {
        digit[len ++] = x % 10;
        x /= 10;
    }

    int sum[2] = {0, 0};
    ll res = 0;
    for(int i = len - 1; i > -1; i --) {
        if(digit[i] == 0) continue;

        for(int num = 0; num < digit[i]; num ++) {
            int j = ((K - sum[0] - num * p10[i]) % K + K) % K;
            int k = ((K - sum[1] - num) % K + K) % K;
            res += dp[i][j][k];
        }

        sum[0] += digit[i] * p10[i];
        sum[0] %= K;
        sum[1] += digit[i];
        sum[1] %= K;
    }

    return res + (sum[0] == 0 && sum[1] == 0);
}

int main() {
    p10[0] = 1;
    for(int i = 1; i < 10; i ++) p10[i] = p10[i - 1] * 10LL;
    int T, A, B, K;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d%d", &A, &B, &K);
        ll ans = 0;
        if(K < 85) {
            init(K);
            ans = calc(B, K) - calc(A - 1, K);
        }
        printf("Case %d: %lld\n", cas, ans);
    }
    return 0;
}
