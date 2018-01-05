#include<bits/stdc++.h>
using namespace std;

const int N=111;
int T;
char s[N], t[N];
string dp[N][N];
int main() {
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++) {
        scanf("%s%s", s+1, t+1);
        int n=strlen(s+1);
        int m=strlen(t+1);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++) dp[i][j].clear();
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+s[i];
                else {
                    if(dp[i-1][j].size()>dp[i][j-1].size()) dp[i][j]=dp[i-1][j];
                    else if(dp[i][j-1].size()>dp[i-1][j].size()) dp[i][j]=dp[i][j-1];
                    else {
                        if(dp[i-1][j]<dp[i][j-1]) dp[i][j]=dp[i-1][j];
                        else dp[i][j]=dp[i][j-1];
                    }
                }
            }
        }
        if(!dp[n][m].size()) dp[n][m]=":(";
        printf("Case %d: %s\n", ca, dp[n][m].c_str());
    }
    return 0;
}
