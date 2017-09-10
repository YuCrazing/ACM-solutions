#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;
const int N=1e5+5;
int dp[N][2], a[N], ans;
vector<pair<int,int> > g[N];

void init(int n) {
    for(int i = 1; i <= n; i++) dp[i][0]=dp[i][1]=-INF;
    for(int i = 1; i <= n; i++) g[i].clear();
    ans=0;
}

void dfs(int u, int fa) {
    int res0=-INF, res1=-INF;
    for(int i = 0; i < g[u].size(); i++) {
        int v=g[u][i].first;
        int w=g[u][i].second;
        if(v==fa) continue;
        dfs(v, u);
        res0=max(res0, dp[v][0]-a[v]-w+a[u]);
        res1=max(res1, dp[v][1]+a[v]-w-a[u]);
    }
    dp[u][0]=0;
    if(res0!=-INF)
        dp[u][0]=max(0,res0);
    dp[u][1]=0;
    if(res1!=-INF)
        dp[u][1]=max(0,res1);
    ans=max(ans, dp[u][0]);
    ans=max(ans, dp[u][1]);
    ans=max(ans, dp[u][0] + dp[u][1]);
}

int T, n, u, v, w;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        init(n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i < n; i++) {
            scanf("%d%d%d", &u, &v, &w);
            g[v].push_back(make_pair(u, w));
            g[u].push_back(make_pair(v, w));
        }
        dfs(1, 0);
        //for(int i = 1; i <= n; i++) printf("%d %d %d %d\n", i, dp[i][0], dp[i][1], dp[i][0]+dp[i][1]);
        printf("%d\n", ans);

    }
    return 0;
}
