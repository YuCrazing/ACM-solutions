#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXM = 1e5 + 2;
const int MAXN = 2e4 + 2;

struct Edge{
    int to, next;
};

struct Graph{
    int head[MAXN], vis[MAXN], en, n, ccn;
    bool have[MAXN];
    Edge e[MAXM << 1];
    pair<int, int> cc[MAXN];

    void init(){
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        memset(have, 0, sizeof(have));
        for(int i = 0; i < MAXN; i ++) cc[i] = make_pair(0, 0);
        vis[0] = 1;
        n = en = ccn = 0;
    }
    void addedge(int u, int v){
        e[en].to = v;
        e[en].next = head[u];
        head[u] = en ++;

        e[en].to = u;
        e[en].next = head[v];
        head[v] = en ++;
    }
    void dfs(int u, int fa){
        vis[u] = 3 - vis[fa];
        if(vis[u] == 1) cc[ccn].first ++;
        else cc[ccn].second ++;
        int v;
        for(int i = head[u]; i != -1; i = e[i].next){
            v = e[i].to;
            if(!vis[v]) dfs(v, u);
        }
    }
};

int main(){
    int T, n, u, v;
    Graph g;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        g.init();
        scanf("%d", &n);
        for(int i = 0; i < n; i ++){
            scanf("%d%d", &u, &v);
            g.have[u] = g.have[v] = 1; // Only consider nodes appear in input.
            g.n = max(g.n, max(u, v));
            g.addedge(u, v);
        }
        for(int i = 1; i <= g.n; i ++)
            if(g.have[i] && !g.vis[i]) {
                g.ccn ++;
                g.dfs(i, 0);
            }
        int sum = 0;
        for(int i = 1; i <= g.ccn; i ++) sum += max(g.cc[i].first, g.cc[i].second);
        printf("Case %d: %d\n", cas, sum);
    }
    return 0;
}
