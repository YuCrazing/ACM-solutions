#include<bits/stdc++.h>
using namespace std;

const int N = 222;
int g[N][N], dis[N], n, m, d;
bool vis[N][N], in[N];

int spfa(int s, int t) {
    queue<int> Q;
    Q.push(s);
    in[s] = true;
    for(int i = 0; i < n; ++i) dis[i] = 1e9;
    dis[s]=0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        in[u]=false;
        for(int i = 0; i < n; ++i) {
            if(g[u][i]!=-1 && dis[i] > dis[u] + g[u][i]) {
                dis[i] = dis[u] + g[u][i];
                if(!in[i]) {
                    in[i]=true;
                    Q.push(i);
                }
            }
        }
    }
    return dis[t];
}

int main() {
    scanf("%d%d", &n, &m);
    memset(g, -1, sizeof(g));
    int u, v, w;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        --u;
        --v;
        g[u][v]=g[v][u]=w;
    }

    scanf("%d", &d);
    for(int i = 0; i < d; ++i) {
        scanf("%d%d", &u, &v);
        --u;
        --v;
        vis[u][v]=vis[v][u]=true;
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(!vis[i][j] && g[i][j]!=-1) g[i][j]=0;

    scanf("%d%d", &u, &v);
    printf("%d\n", spfa(u-1, v-1));
    return 0;
}
