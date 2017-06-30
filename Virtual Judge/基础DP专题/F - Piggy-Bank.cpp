#include<bits/stdc++.h>
using namespace std;

const int INF = (1<<31)-1; // OK
const int N = 1e4 + 5;
int n, E, F, T, dp[N], w[N], p[N];

void init() {
    for(int i = 0; i < N; i++) dp[i] = INF;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &E, &F, &n);

        init();

        for(int i = 1; i <= n; i++) scanf("%d%d", &p[i], &w[i]);

        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= F-E; j++) {
                if(j >= w[i] && dp[j-w[i]] < INF)
                    dp[j] = min(dp[j], dp[j-w[i]] + p[i]);
            }
        }

        if(dp[F-E] == INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[F-E]);

    }
    return 0;
}
