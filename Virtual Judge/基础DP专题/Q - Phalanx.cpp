/*
    dp[i][j]:以(i,j)为左下角的最大对称方阵
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1011;
int n, dp[N][N];
char s[N][N];
int main() {
    while(scanf("%d", &n) != EOF && n) {
        for(int i = 0; i < n; i++) scanf("%s", s[i]);

        for(int i = 0; i < n; i++) dp[0][i] = 1;
        for(int i = 0; i < n; i++) dp[i][n] = 0;

        int ans = 1;
        for(int i = 1; i < n; i++)
            for(int j = n-1; j >= 0; j--) {
                int k = 0;
                while(j+k<n&&i-k>=0&&s[i][j+k]==s[i-k][j]&&k<=dp[i-1][j+1]) k++;
                dp[i][j] = k;
                ans = max(ans, dp[i][j]);
            }
        printf("%d\n", ans);
    }
    return 0;
}
