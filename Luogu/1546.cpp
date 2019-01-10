#include<bits/stdc++.h>
using namespace std;

const int N = 111;
const int inf = 1e9;
int g[N][N], dis[N], n;
bool vis[N];

int prim() {

    for(int i = 0; i < n; ++i) dis[i] = inf;
    dis[0] = 0;

    for(int k = 1; k < n; ++k) {
        int u = -1, mi = inf;
        for(int i = 0; i < n; ++i) {
            if(!vis[i] && dis[i] < mi) {
                mi = dis[i];
                u = i;
            }
        }
        vis[u] = true;
        for(int i = 0; i < n; ++i) {
            if(!vis[i] && dis[i] > g[u][i]) {
                dis[i] = g[u][i];
            }
        }
    }
    for(int i = 0; i < n; ++i) dis[0] += dis[i];
    return dis[0];
}

int main() {

    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d", &g[i][j]);

    printf("%d\n", prim());

    return 0;
}
