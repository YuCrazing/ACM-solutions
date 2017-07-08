#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 6e4 + 5;
const int M = 1e5 + 2e4 + 5;
const ll INF = 8e18;

struct Edge {
    int w, next, v;
    Edge(int _v=0, int _w=0, int _next=0):next(_next), w(_w), v(_v) {};
} e[M];

int head[N], en;
bool vis[N];
ll dis[N];

void init() {
    memset(head, -1, sizeof(head));
    en = 0;
}

void add(int u, int v, int w) {
    e[en] = Edge(v, w, head[u]);
    head[u] = en++;
}

int n, m, m1, m2, k;

void spfa(int s) {
    for(int i = 0; i < N; i++) {//
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        vis[u] = 0; // !!!
        q.pop();
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}


int main() {

    scanf("%d%d", &n, &m);

    init();

    int u, v, w;
    for(int i = 0; i < m; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &u);
            add(u, i + 1 + n, 0);
            add(i + 1 + 2*n, u, 0);
        }
    }

    scanf("%d", &m1);
    for(int i = 0; i < m1; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }

    scanf("%d", &m2);
    for(int i = 0; i < m2; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add(u + n, v + 2*n, w);
        add(v + n, u + 2*n, w);
    }

    scanf("%d%d", &u, &v);

    spfa(u);
    ll ans = dis[v];
    if(ans == INF) ans = -1;
    printf("%lld\n", ans);

    return 0;
}
