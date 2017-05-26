#include<bits/stdc++.h>
using namespace std;

const int N = 8;

bool g[N][N], used[N];
int T, n, maxx, ans[N], in[N], dis[N];

void init() {
    memset(ans, 0, sizeof(ans));
    memset(g, 0, sizeof(g));
}

void bfs(int u) {
    used[u] = 1;
    dis[u] = 1;
    int t = 0;
    for(int i = 0; i < n; i++) {
        if(dis[i]) {
            if(used[i]) continue;
            if(i != u && g[u][i]) t = max(t, dis[i]);
        } else {
            if(i != u && g[u][i]) {
                bfs(i);
                t = max(t, dis[i]);
            }
        }
    }
    dis[u] += t;
    maxx = max(maxx, dis[u]);
    used[u] = 0;
}

void check() {
    memset(in, 0, sizeof(in));
    memset(dis, 0, sizeof(dis));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && g[j][i]) in[i]++;
        }
    }

    maxx = 0;
    for(int i = 0; i < n; i++) if(!in[i]) {
            memset(used, 0, sizeof(used));
            bfs(i);
        }
    for(int i = 0; i < n; i++) if(!dis[i]) {
            memset(used, 0, sizeof(used));
            bfs(i);
        }
//    printf("maxx = %d, ans[maxx] = %d\n", maxx, ans[maxx]);
    assert(maxx == n); // All is n!!!
    ans[maxx]++;
}

void dfs(int a, int b) {
    if(a == n - 1) {
        check();
        return ;
    }
    g[a][b] = 1;
    g[b][a] = 0;
    if(b == n - 1) dfs(a + 1, a + 2);
    else dfs(a, b + 1);
    g[a][b] = 0;
    g[b][a] = 1;
    if(b == n - 1) dfs(a + 1, a + 2);
    else dfs(a, b + 1);
}

int main() {

//    freopen("out.out", "w", stdout);

    scanf("%d", &T);
    while(T--) {
        init();

        scanf("%d", &n);

        dfs(0, 1);

        for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);

    }
    return 0;
}
