#include<bits/stdc++.h>
using namespace std;

const int N=26;
int mp[N][N];
int n;
int dp[10010][N];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &mp[i][j]);
        }
    }
    int INF=1e9;
    for(int i = 0; i < N; i++) dp[1][i]=0;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j]=1e9;
            for(int k=0; k<N; k++) {
                dp[i][j] = min(dp[i][j], dp[i-1][k]+mp[k][j]);
            }
        }
    }
    int ans=INF;
    for(int i = 0; i < N; i++) ans=min(ans, dp[n][i]);
    printf("%d\n", ans);
    return 0;
}
