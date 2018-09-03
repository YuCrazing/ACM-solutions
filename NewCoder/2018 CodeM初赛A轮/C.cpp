#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
const int N=1e5+5;
vector<tuple<int,int,int> > g[N];

int fa[N][17], deg[N], cost[N], n, m;
ll cost[N];

ll dfs(int u, int f) {
    fa[u][0]=f;
    if(u==1) deg[u]=0;
    else deg[u]=deg[f]+1;
    cost[u]=0;
    for(int i = 0; i < g[u].size(); ++i) {
        int v=get<0>(g[u][i]);
        int w=get<1>(g[u][i]);
        int z=get<2>(g[u][i]);
        cost[u]+=((z&1)?(z+1):z)*(ll)(w)%mod;
        cost[u]%=mod;
        if(v==f) continue;
        cost[u]+=dfs(v, u);
        cost[u]%=mod;
    }
    return cost[u];
}

void init() {
    dfs(1, 0);
    for(int j = 1; j < 17; ++j) {
        for(int i = 0; i < n; ++i)fa[i][j]=fa[fa[i][j-1]][j-1];
    }
}

int lca(int u, int v) {
    if(deg[u] > deg[v])swap(u,v);
    int hu = deg[u], hv = deg[v];
    int tu = u, tv = v;
    for(int det = hv-hu, i = 0; det ; det>>=1, i++)
        if(det&1)
            tv = fa[tv][i];
    if(tu == tv)return tu;
    for(int i = 16; i >= 0; i--) {
        if(fa[tu][i] == fa[tv][i])
            continue;
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    return fa[tu][0];
}

int getRoot(int u){
    for(int i = 16; i > )
}

ll calc(int x, int y){
    int f=lca(x, y);
    ll ans=0;
    if(x==f){
        if(cost[x]==0){
            ans+=
        }
    }else if()
}

int main() {
    int x, y, w, z;
    scanf("%d", &n);
    for(int i = 0; i < n-1; ++i) {
        scanf("%d%d%d%", &x, &y, &w, &z);
        z=max(0, z);
        g[x].push_back(tuple<int,int,int>{y,w,z});
        g[y].push_back(tuple<int,int,int>{x,w,z});
    }
    init();
    scanf("%d", &m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &x, &y);
        printf("%lld\n", calc(x, y));
    }
    return 0;
}

