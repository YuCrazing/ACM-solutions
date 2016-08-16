#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 205;
int w[N][N], a[N], dis[N], cnt[N], n, T;
bool vis[N];
vector<int> g[N];

int cube(int x) {
    return x * x * x;
}

bool spfa() {

    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    memset(dis, 0x3f, sizeof(dis));

    dis[1] = 0;
    queue<int> Q;
    Q.push(1);
    vis[1] = 1;
    cnt[1] ++;
    int u, v, sz;
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        vis[u] = 0;
        sz = g[u].size();
        for(int i = 0; i < sz; i ++) {
            v = g[u][i];
            if(dis[v] > dis[u] + w[u][v]) {
                dis[v] = dis[u] + w[u][v];
                if(vis[v]) continue;
                Q.push(v);
                vis[v] = 1;
                cnt[v] ++;
                if(cnt[v] > n) return false;
            }
        }
    }
    return true;
}

int main() {

    int u, v, q, m;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        memset(w, 0, sizeof(w));
        scanf("%d", &m);
        for(int i = 1; i <= n; i ++) g[i].clear();
        for(int i = 0; i < m; i ++) {
            scanf("%d%d", &u, &v);
            w[u][v] = cube(a[v] - a[u]);
            g[u].push_back(v);
        }


        bool ok = spfa(); // what if ok == 0 ?

        scanf("%d", &q);
        printf("Case %d:\n", cas);
        for(int i = 0; i < q; i ++) {
            scanf("%d", &v);
            if(dis[v] == inf || dis[v] < 3) printf("?\n");
            else printf("%d\n", dis[v]);
        }
    }
    return 0;
}
