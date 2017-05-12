#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int T, n, q, dp[N][17];

void initRMQ() {
    for(int i = 0; i < n; i++) scanf("%d", &dp[i][0]);
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 0; i + (1<<j) - 1 < n; i++) {
            dp[i][j] = min( dp[i][j - 1], dp[i + (1<<(j - 1))][j - 1]);
        }
    }
}

int RMQ(int l, int r) {
    int k = 0;
    while((1<<k) <= r - l + 1) k++;
    k --;
    return min(dp[l][k], dp[r - (1<<k) + 1][k]);
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &q);
        initRMQ();
        printf("Case %d:\n", ca);
        for(int i = 0; i < q; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", RMQ(l - 1, r - 1));
        }
    }
    return 0;
}
