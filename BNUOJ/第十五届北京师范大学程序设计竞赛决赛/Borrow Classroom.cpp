#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 4;
int n, q, T, en, head[N], dis[N], fa[N], dp[N][21];
struct Edge {
    int v, next;
} e[N << 1];

void init() {
    memset(head, -1, sizeof(head));
    en = 0;

    memset(fa, -1, sizeof(fa));
    memset(dis, 0, sizeof(dis));
}

void add(int u, int v) {
    e[en].v = v;
    e[en].next = head[u];
    head[u] = en++;

    e[en].v = u;
    e[en].next = head[v];
    head[v] = en++;
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    dis[s] = 1;
    fa[s] = s;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if(!dis[v]) {
                dis[v] = dis[u] + 1;
                fa[v] = u;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; i++) dis[i] --;

    for(int i = 1; i <= n; i++) dp[i][0] = fa[i];
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 1; i <= n; i++) {
            int t = dp[i][j - 1];
            dp[i][j] = dp[t][j - 1];
        }
    }
}

int lca(int x, int y) {
    if(dis[x] > dis[y]) swap(x, y);
    int t = dis[y] - dis[x];
    for(int i = 20; i >= 0; i--) if(t & (1<<i)) y = dp[y][i];
    if(x == y) return x;
    for(int i = 20; i >= 0; i--) {
        if(dp[x][i] != dp[y][i]) {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    assert(dp[x][0] == dp[y][0]);
    return dp[x][0];
}

int main() {
    scanf("%d", &T);
    while(T--) {

        init();

        scanf("%d%d", &n, &q);
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
        }

        bfs(1);

        for(int i = 0; i < q; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            int x = dis[b] + dis[c] - 2 * dis[lca(b, c)];

            int lc = lca(a, c);
            bool ok;
            if(lc == 1) {
                if(dis[a] < dis[c] + x) ok = true;
                else ok = false;
            } else {
                if(dis[a] <= dis[c] + x) ok = true;
                else ok = false;
            }
            printf(ok ? "YES\n" : "NO\n");
        }

    }
    return 0;
}
