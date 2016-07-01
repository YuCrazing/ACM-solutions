#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > g[30000];
int vis[30000];

int bfs(int u) {
    for(int i = 0; i < 30000; i ++) vis[i] = 0;
    int maxDis = -1, id;
    queue<int> Q;
    Q.push(u);
    vis[u] = 1;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if(vis[u] - 1 > maxDis) {
            maxDis = vis[u] - 1;
            id = u;
        }
        int sz = g[u].size();
        for(int i = 0; i < sz; i ++) {
            int v = g[u][i].first;
            if(!vis[v]) {
                Q.push(v);
                vis[v] = vis[u] + g[u][i].second;
            }
        }
    }
    return id;
}
int main() {
    int T, n, u, v, w, best;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);

        for(int i = 0; i < n; i ++) g[i].clear();
        for(int i = 0; i < n - 1; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));
        }

        best = bfs(0);
        best = bfs(best);
        printf("Case %d: %d\n", cas, vis[best] - 1);
    }
    return 0;
}
