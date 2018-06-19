/*
    Kruskal 最小生成树，分析后可知，s 到 t 的答案就是最小生成树上 s 到 t 路径上权值最大的边的边权。
    倍增即可。
*/

#include<bits/stdc++.h>
using namespace std;

const int N=5e4 + 5;
const int M=1e5 + 5;
const int INF=1e9;
const int DEG=17;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& t)const {
        return w < t.w;
    }
} e[M];

int f[N], fa[N][DEG], dep[N], mx[N][DEG], n, m, q, T;
vector<pair<int,int> > g[N];

void init() {
    for(int i = 1; i <= n; ++i) {
        f[i]=i;
        g[i].clear();
    }
}

int find(int u) {
    if(u==f[u]) return u;
    return f[u]=find(f[u]);
}

void merge(int u, int v) {
    int fu=find(u);
    int fv=find(v);
    f[fu]=fv;
}

void dfs(int u, int pre) {
    for(int i = 0; i < g[u].size(); ++i) {
        int v=g[u][i].first;
        int w=g[u][i].second;
        if(pre==v) continue;
        fa[v][0]=u;
        mx[v][0]=w;
        dep[v]=dep[u]+1;
        dfs(v, u);
    }
}

int solve(int u, int v) {
    int ans=0;
    if(dep[v] > dep[u]) swap(u, v);
    int d=dep[u]-dep[v];
    for(int i = 0; i < DEG; ++i)
        if(d&(1<<i)) {
            ans=max(ans, mx[u][i]);
            u=fa[u][i];
        }

    if(u==v) return ans;

    for(int i = DEG-1; i >= 0; --i) {
        if(fa[u][i]==fa[v][i]) continue;
        ans=max(ans, mx[u][i]);
        ans=max(ans, mx[v][i]);
        u=fa[u][i];
        v=fa[v][i];
    }
    ans=max(ans, mx[u][0]);
    ans=max(ans, mx[v][0]);
    return ans;
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        }
        init();
        sort(e, e+m);
        for(int i = 0; i < m; ++i) {
            if(find(e[i].u)==find(e[i].v)) continue;
            merge(e[i].u, e[i].v);
            g[e[i].u].push_back({e[i].v, e[i].w});
            g[e[i].v].push_back({e[i].u, e[i].w});
        }

        fa[1][0]=mx[1][0]=dep[1]=0;
        dfs(1, 0);

        for(int j = 1; j < DEG; ++j)
            for(int i = 1; i <= n; ++i) {
                fa[i][j]=fa[fa[i][j-1]][j-1];
                mx[i][j]=max(mx[i][j-1], mx[fa[i][j-1]][j-1]);
            }

        scanf("%d", &q);
        printf("Case %d:\n", ca);
        for(int i = 0; i < q; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", solve(u, v));
        }

    }
    return 0;
}
