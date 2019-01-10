#include<bits/stdc++.h>
using namespace std;

const int N = 303;
const int inf = 0x3f3f3f3f;
int n, m, q, dis[N][N];

void floyd() {

    for(int i = 0; i < n; ++i) {
        dis[i][i] = 0;
    }
    for(int j = 0; j < m; ++j)
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(dis[i][j] > max(dis[i][k], dis[k][j]))
                    dis[i][j] = max(dis[i][k], dis[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    memset(dis, 0x3f, sizeof(dis));
    int u, v, w;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        -- u;
        -- v;
        dis[u][v] = w;
    }
    floyd();
    for(int i = 0; i < q; ++i) {
        scanf("%d%d", &u, &v);
        -- u;
        -- v;
        printf("%d\n", dis[u][v]==inf?-1:dis[u][v]);
    }
    return 0;
}
