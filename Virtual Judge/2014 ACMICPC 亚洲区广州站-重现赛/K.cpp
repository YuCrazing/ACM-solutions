#include<bits/stdc++.h>
using namespace std;

const int N=33;
const int INF=0x3f3f3f3f;
bool vis[N];
int dis[N];
vector<pair<int, int> > g[N];
int spfa(int s, int t, int no) {
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(s);
    dis[s]=0;
    vis[s]=true;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i = 0; i < g[u].size(); i++) {
            int v=g[u][i].first;
            if(v==no) continue;
            int w=g[u][i].second;
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                if(!vis[v]) {
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    return dis[t];
}

void init(int n) {
    for(int i = 1; i <= n; i++) g[i].clear();
}
int main() {
    int n, m, u, v, w;
    while(scanf("%d%d", &n, &m) != EOF) {
        if(!n&&!m) break;
        init(n);
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back(pair<int, int>(v, w));
            g[v].push_back(pair<int, int>(u, w));
        }
        int ans=0;
        for(int i = 2; i < n; i++) {
            ans=max(ans, spfa(1, n, i));
        }
        if(ans==INF) puts("Inf");
        else printf("%d\n", ans);

    }
    return 0;
}
