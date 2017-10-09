#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
const int N=222;

int dp[N][N], ans[N][N], n, k;
vector<int> g[N], t;

void init(){
    for(int i = 0; i <= n; i++){
        g[i].clear();
        for(int j = 0; j <= k; j++){
            dp[i][j]=ans[i][j]=0;
        }
    }
}

void calc(int u, int fa){
    t.clear();
    for(int i = 0; i < g[u].size(); i++) if(g[u][i]!=fa) t.push_back(g[u][i]);

    for(int i = 0; i <= t.size(); i++)
        for(int j = 0; j <= k; j++)
            dp[i][j]=0;

    dp[0][0]=1;
    for(int i = 1; i <= t.size(); i++){
        for(int j = 0; j <= k; j++){
            for(int x = 0; x <= j; x++){
                dp[i][j]+=1LL * ans[t[i-1]][x]%mod * 1LL * dp[i-1][j-x]%mod;
                dp[i][j]%=mod;
            }
        }
    }

    ans[u][0]=1;
    for(int i = 1; i <= k; i++) {
        ans[u][i]=dp[t.size()][i-1];
        printf("ans[%d][%d]=%d\n", u, i, ans[u][i]);
    }
}

void dfs(int u, int fa){
    for(int i = 0; i < g[u].size(); i++){
        if(g[u][i]!=fa) dfs(g[u][i], u);
    }
    calc(u, fa);
}

int main(){
    while(scanf("%d%d", &n, &k)!=EOF){
        init();
        int u, v;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        int sum=0;
        for(int i = 1; i <= n; i++) sum=(sum+ans[i][k])%mod;
        printf("%d\n", sum);
    }
    return 0;
}
