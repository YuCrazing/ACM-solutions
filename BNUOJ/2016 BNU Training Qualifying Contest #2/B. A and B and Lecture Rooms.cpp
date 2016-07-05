#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 10;
const int DEG = 20;

struct Edge {
    int to, next;
} edge[MAXN * 2];
int head[MAXN], tot;

void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot ++;
}

void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

int fa[MAXN][DEG];
int deg[MAXN];

void BFS(int root) {
    queue<int> que;
    deg[root] = 0;
    fa[root][0] = root;
    que.push(root);
    while(!que.empty()) {
        int tmp = que.front();
        que.pop();
        for(int i = 1; i < DEG; i ++) fa[tmp][i] = fa[fa[tmp][i - 1]][i - 1];
        for(int i = head[tmp]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if(v == fa[tmp][0]) continue;
            deg[v] = deg[tmp] + 1;
            fa[v][0] = tmp;
            que.push(v);
        }
    }
}

int LCA(int u, int v) {
    if(deg[u] > deg[v]) swap(u, v);
    int hu = deg[u], hv = deg[v];
    int tu = u, tv = v;
    for(int det = hv - hu, i = 0; det; det >>= 1, i++)
        if(det&1) tv = fa[tv][i];
    if(tv == tu) return tu;
    for(int i = DEG - 1; i >= 0; i --) {
        if(fa[tu][i] == fa[tv][i]) continue;
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    return fa[tu][0];
}

int cnt[MAXN];
int DFS(int u, int pre) {
    int res = 1;
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(v == pre) continue;
        res += DFS(v, u);
    }
    return cnt[u] = res;
}

int FindAncestor(int u, int n) {
    int tu = u;
    for(int i = 0; n; n >>= 1, i ++) if(n & 1) tu = fa[tu][i];
    return tu;
}
int main() {
    init();
    int n, u, v, m;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i ++) {
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    int root = 1;
    BFS(root);
    DFS(root, -1);

    scanf("%d", &m);
    for(int i = 0; i < m; i ++) {
        scanf("%d%d", &u, &v);
        int ans;
        if(u == v) ans = n;
        else {
            int lca = LCA(u, v);
            int dis = deg[u] + deg[v] - 2 * deg[lca];
            if(deg[u] == deg[v]) {
//                ans = n - cnt[lca] + 1; //wrong. lca can have several sons besides u&v.
                int tu = FindAncestor(u, dis / 2 - 1);
                int tv = FindAncestor(v, dis / 2 - 1);
                ans = n - cnt[tu] - cnt[tv];
            } else {
                if(deg[u] > deg[v]) swap(u,v);
                if(dis & 1) ans = 0;
                else {
                    int mid = FindAncestor(v, dis / 2);
                    int mid_son = FindAncestor(v, dis / 2 - 1);

                    ans = cnt[mid] - cnt[mid_son];
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

/*
7
1 2
1 3
1 5
1 6
1 7
2 4
1
2 3
*/
