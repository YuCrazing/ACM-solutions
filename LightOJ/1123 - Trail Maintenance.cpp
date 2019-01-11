#include<bits/stdc++.h>
using namespace std;

const int N = 222;
vector<pair<int, int> > g[N];
bool vis[N];

int ans, fa[N];
void dfs(int u) {
    ++ans;
    vis[u]=true;
    for(int i = 0; i < g[u].size(); ++i) {
        int v=g[u][i].first;
        int w=g[u][i].second;
        if(!vis[v]) {
            fa[v]=u;
            dfs(v);
        }
    }
}

int main() {
    int n, m, u, v, w, T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &m);
        for(int k = 0; k < m; ++k) {
            scanf("%d%d%d", &u, &v, &w);
            if(u!=v) {
                bool exist=false;
                for(int i = 0; i < g[u].size(); ++i) {
                    if(g[u][i].first==v) {
                        exist=true;
                        g[u][i].second=min(g[u][i].second, w);
                        break;
                    }
                }
                if(exist) {
                    for(int i = 0; i < g[u].size(); ++i) {
                        if(g[v][i].first==u) {
                            exist=true;
                            g[v][i].second=min(g[v][i].second, w);
                            break;
                        }
                    }
                } else {
                    g[u].push_back({v, w});
                    g[v].push_back({u, w});
                }
                ans = fa[u] = 0;
                for(int i = 1; i <= n; ++i) vis[i] = false;
                dfs(u);
                if(ans==n) {
                    int mx=0, cur=v, sum=0;
                    while(cur!=u) {

                    }
                } else ans=-1;
            }
            printf("Case %d: %d\n", ca, ans);
        }
    }
    return 0;
}
