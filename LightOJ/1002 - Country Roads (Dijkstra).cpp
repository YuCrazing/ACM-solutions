#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))


const int MAXN = 555;

int head[MAXN], dis[MAXN], T, n, m, cnt;
bool vis[MAXN];
struct Edge {
    int next, to, w;
} e[40000]; //

struct Node {
    int v, val;

    Node (int _v = 0, int _val = 0):v(_v),val(_val) {};
    bool operator<(const Node &b)const {
        return val > b.val; // compare with val, not dis[v] ?
    }
};

void addedge(int u, int v, int w) {
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt ++;

    e[cnt].to = u;
    e[cnt].w = w;
    e[cnt].next = head[v];
    head[v] = cnt ++;
}

void init() {
    cnt = 0;
    clr(head, -1);
}

void Dijkstra(int src) {
    clr(vis, 0);
    clr(dis, 0x3f);
    dis[src] = 0;

    priority_queue<Node> Q;
    Q.push(Node(src, dis[src]));
    while(!Q.empty()) {
        int cur = Q.top().v;
        Q.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(int i = head[cur]; i != -1; i = e[i].next) {
            int w = max(e[i].w, dis[cur]);
            if(dis[e[i].to] <= w) continue;
            dis[e[i].to] = w;
            Q.push(Node(e[i].to, dis[e[i].to]));
        }
    }
}
int main() {

    int u, v, w, t;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        init();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
        }
        scanf("%d", &t);
        Dijkstra(t);
        printf("Case %d:\n", cas);
        for(int i = 0; i < n; i ++) {
            if(dis[i] == 0x3f3f3f3f) printf("Impossible\n");
            else printf("%d\n", dis[i]);
        }
    }
    return 0;
}
