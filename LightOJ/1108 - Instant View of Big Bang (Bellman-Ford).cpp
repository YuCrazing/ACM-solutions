/*
    求负环上的点以及能走到负环的点
    首先有一个等价变换的技巧：
    把所有边的方向反向后，能走到负环的点，就变成了负环能走到的点。这样找到负环上的点后进行BFS即可。
    找负环上的点可以使用 Bellman-Ford/SPFA 算法（但是该算法不能找到所有负环上的点？）
*/

#include<bits/stdc++.h>
using namespace std;

const int N=1011;

vector<pair<int,int> > g[N];
bool vis[N], onCyc[N], cycle;
int dis[N];
queue<int> q;

void init(int n) {
    for(int i = 0; i < n; i++) {
        g[i].clear();
        onCyc[i]=cycle=false;
    }
}

void bfs(int n) {
    while(!q.empty()) q.pop();

    for(int i = 0; i < n; i++) {
        if(onCyc[i]) {
            q.push(i);
            vis[i]=true;
        } else vis[i]=false;
    }

    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++) {
            int v=g[u][i].first;
            if(!vis[v]) {
                q.push(v);
                onCyc[v]=true;
                vis[v]=true;
            }
        }
    }
}

void bellman_ford(int n) {
    for(int i = 0; i < n; ++i) dis[i] = 0;
    for(int k = 1; k < n; ++k) {
        for(int u = 0; u < n; ++u) {
            for(int i = 0; i < g[u].size(); ++i) {
                int v = g[u][i].first;
                int w = g[u][i].second;
                if(dis[v] > w + dis[u]) dis[v] = dis[u] + w;
            }
        }
    }
    for(int u = 0; u < n; ++u) {
        for(int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].first;
            int w = g[u][i].second;
            if(dis[v] > dis[u] + w) {
                // printf("dis[%d]=%d (dis[%d]=%d %d)\n", v, dis[v], u, dis[u], w);
                onCyc[u]=onCyc[v]=cycle=true;
            }
        }
    }
    bfs(n);
}

int main() {
    int n, m, T, u, v, w;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++) {
        scanf("%d%d", &n, &m);
        init(n);
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            g[v].push_back(pair<int,int>(u, w));
        }

        bellman_ford(n);

        printf("Case %d:", ca);
        if(cycle) {
            for(int i = 0; i < n; i++) if(onCyc[i]) printf(" %d", i);
        } else printf(" impossible");
        puts("");
    }
    return 0;
}

/*

10
10 4
0 1 1
1 0 -2
0 2 1
2 1 1
10 5
0 1 1
1 2 1
2 3 1
3 4 1
4 0 -5

*/
