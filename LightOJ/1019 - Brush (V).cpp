#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool vis[111];
int dis[111], g[111][111];
void Dij(int s, int n) {
    for(int i = 1; i <= n; i++) {
        dis[i] = 0x3f3f3f3f;
        vis[i] = 0;
    }
    dis[s] = 0;
    for(int i = 0; i < n; i ++) {
        int maxDis = 0x3f3f3f3f, id;
        for(int j = 1; j <= n; j ++)
            if(!vis[j] && maxDis > dis[j]) {
                maxDis = dis[j];
                id = j;
            }
        vis[id] = 1;
        for(int j = 1; j <= n; j ++)
            if(g[id][j] && g[id][j] + dis[id] < dis[j])
                dis[j] = dis[id] + g[id][j];
    }
}
int main() {
    int T, n, m, u, v, w;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        memset(g, 0, sizeof(g));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            if(!g[u][v]) g[u][v] = w;
            else g[u][v] = min(g[u][v], w);
            if(!g[v][u]) g[v][u] = w;
            else g[v][u] = min(g[v][u], w);
        }
        Dij(1, n);
        printf("Case %d: ", cas);
        if(dis[n] == 0x3f3f3f3f) printf("Impossible\n");
        else printf("%d\n", dis[n]);

    }
    return 0;
}
