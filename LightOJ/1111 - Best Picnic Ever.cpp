#include<bits/stdc++.h>
using namespace std;

const int N = 1011;
bool vis[N];
int pos[N];
vector<int> g[N];
bitset<N> st[2];

void dfs(int u) {
    vis[u]=1;
    for(int i = 0; i < g[u].size(); ++i) {
        if(!vis[g[u][i]]) dfs(g[u][i]);
    }
}

int main() {
    int n, m, k, u, v, T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d%d", &k, &n, &m);
        for(int i = 0; i < k; ++i) scanf("%d", &pos[i]);
        for(int i = 1; i <= n; ++i) g[i].clear();
        for(int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
        }
        st[0].set(); // set all bits to 1
        for(int i = 0; i < k; ++i) {
            memset(vis, 0, sizeof(vis));
            dfs(pos[i]);
            st[1].reset(); // set all bits to 0 (no .clear())
            for(int j = 1; j <= n; ++j) if(vis[j]) st[1].set(j);
            st[0]=(st[0]&st[1]);
        }
        printf("Case %d: %d\n", ca, st[0].count());
    }

    return 0;
}

/*

10

2 4 4
2
3
1 2
1 4
2 3
3 4

2 4 2
2
3
1 2
1 4


*/
