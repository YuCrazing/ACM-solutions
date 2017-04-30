#include<bits/stdc++.h>
using namespace std;

const int N = 52;
const int V = 52;
const int M = 102;
const int MAX = N * V * M / 2;
int dp[MAX], v[N], m[N], n;
int main() {
    while(scanf("%d", &n) && n >= 0) {

        for(int i = 0; i < n; i++)scanf("%d%d", &v[i], &m[i]);

        int sum = 0, mid;
        for(int i = 0; i < n; i++) sum += v[i] * m[i];
        mid = sum / 2;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m[i]; j++)
                for(int k = mid; k >= v[i]; k--) // Caution: Runtime Error.
                    dp[k] += dp[k - v[i]];

        int less;
        for(int i = mid; i >= 0; i--) if(dp[i]) {
                less = i;
                break;
            }
        printf("%d %d\n", sum - less, less);
    }
    return 0;
}
