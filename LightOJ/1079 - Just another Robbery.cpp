#include<bits/stdc++.h>
using namespace std;

const int N = 102;
double dp[N * N], p[N], P;
int v[N], n, T, sum;
int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%lf%d", &P, &n);
        sum = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d%lf", &v[i], &p[i]);
            sum += v[i];
        }
        for(int i = 0; i <= sum; i++) dp[i] = 1.0;
        dp[0] = 0.0;
        for(int i = 1; i <= n; i++) {
            for(int j = sum; j >= 0; j--) {
                if(j >= v[i])
                    dp[j] = min(dp[j], dp[j - v[i]] * (1.0 - p[i]) + p[i]);
//                    dp[j] = min(dp[j], 1.0 - (1.0 - dp[j - v[i]]) * (1.0 - p[i])); // Also OK.
//                    printf("dp[%d][%d] = %f\n", i, j, dp[j]);
            }
        }
        int ans = 0;
        for(int i = sum; i >= 0; i--) if(dp[i] < P) {
                ans = i;
                break;
            }
        printf("Case %d: %d\n", ca, ans);
    }
    return 0;
}

/*

100
0.5 3
1 0.5
2 0.001
3 0.0001

0.991 5
1 1.0
2 0.00001
4 0.5
8 0.99
16 0.01

*/
