/*
    Ò»°ãÍ¼Æ¥Åä or ×´Ì¬Ñ¹ËõDP
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 15;
const int INF = 0x3f3f3f3f; // Is it big enough?

int T, n, m;
int deg[N], dis[N], g[N][N], cost[N][N], dp[1<<N];
bool vis[N];

void init() {
    memset(g, 0, sizeof(g));
    fill(deg, deg + n, 0);
//    fill(dp, dp + n, INF); // Array size Caution!
    fill(dp, dp + (1<<n), INF);
    dp[0] = 0;
}

void dij(int s) {
    fill(dis, dis + n, INF);
    fill(vis, vis + n, false);
    dis[s] = 0;
    for(int i = 1; i < n; i++) {
        int minn = INF, k = -1;
        for(int j = 0; j < n; j ++) {
            if(minn > dis[j] && !vis[j]) {
                k = j;
                minn = dis[j];
            }
        }
        vis[k] = 1;
        for(int j = 0; j < n; j++) {
            if(g[k][j] && dis[j] > dis[k] + g[k][j]) { // g[k][j] != 0
                dis[j] = dis[k] + g[k][j];
            }
        }
    }
    for(int i = 0; i < n; i++) cost[s][i] = cost[i][s] = dis[i];
}

int dfs(int s) {
    if(dp[s] != INF) return dp[s];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            if((s&(1<<j)) && (s&(1<<i))) {
                dp[s] = min(dp[s], dfs(s ^ ((1<<i)|(1<<j))) + cost[i][j]);
            }
        }
    return dp[s];
}

int main() {

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &m);
        int sum = 0;
        init();
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--;
            v--;
            sum += w;
            if(!g[u][v] || g[u][v] > w) {
                g[u][v] = g[v][u] = w;
            }
            deg[u]++;
            deg[v]++;
        }

        for(int i = 0; i < n; i++)
            if(deg[i] & 1) dij(i);

        int s = 0;
        for(int i = 0; i < n; i++)
            if(deg[i] & 1) {
                for(int j = i + 1; j < n; j++) {
                    if(j == i) continue;
                    if(!(deg[j]&1)) continue;
                    dp[(1<<i)|(1<<j)] = cost[i][j];
                }
                s |= (1<<i);
            }
        printf("Case %d: %d\n", ca, dfs(s) + sum);
    }
    return 0;
}

/*

100
6 7
2 3 6
3 1 10
2 5 8
5 6 3
5 4 8
1 1 10
2 6 8

*/
