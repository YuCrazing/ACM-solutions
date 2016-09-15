#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 211;
const int M = 1111;
const double inf = 1e20;

struct Point {
    double x, y, z;
    void read() {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
} p[N];
struct Edge {
    int v, next;
    double w;
} edge[M];

int tot, head[N], fa[N];
double dis[N];
bool vis[N];
queue<int> Q;
stack<int> path;

void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
}

void add(int u, int v, double w) {
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot ++;
}

double dist(Point &a, Point &b) {
    return sqrt(5 * 5 * (a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * ((a.z - b.z)));
}

void spfa(int s) {
    memset(vis, 0, sizeof(vis));
    memset(fa, -1, sizeof(fa));
    for(int i = 0; i < N; i ++) dis[i] = inf;
    dis[s] = 0;

    Q.push(s);
    vis[s] = 1;
    while(!Q.empty()) {
        int u, v;
        double w;

        u = Q.front();
        Q.pop();
        vis[u] = 0;

        for(int i = head[u]; i != -1; i = edge[i].next) {
            v = edge[i].v;
            w = edge[i].w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                fa[v] = u;
                if(!vis[v]) {
                    Q.push(v);
                    vis[v] = 1;
                }
            }
        }

    }
}

void gao(int u, int v) {
    spfa(u);
    while(!path.empty()) path.pop();
    int pre = v;
    while(pre != -1) {
        path.push(pre);
        pre = fa[pre];
    }
    printf("%d", path.top());
    path.pop();
    while(!path.empty()) {
        printf(" %d", path.top());
        path.pop();
    }
    printf("\n");
}

char s[20];
int main() {

    int n, m, u, v, q, cas = 0;

    while(scanf("%d%d", &n, &m) != EOF) {
        if(cas) printf("\n");
        cas ++;
        init();

        for(int i = 0; i < n; i ++) p[i].read();
        for(int i = 0; i < m; i ++) {
            scanf("%d%d%s", &u, &v, s);
            if(!strcmp(s, "walking") || !strcmp(s, "stairs")) {
                add(u, v, dist(p[u], p[v]));
                add(v, u, dist(p[u], p[v]));
            } else if(!strcmp(s, "lift")) {
                add(u, v, 1);
                add(v, u, 1);
            } else if(!strcmp(s, "escalator")) {
                add(u, v, 1);
                add(v, u, 3 * dist(p[u], p[v]));
            }
        }

        scanf("%d", &q);
        while(q --) {
            scanf("%d%d", &u, &v);
            gao(u, v);
        }
    }
    return 0;
}
/*

6 7
3 2 3
3 5 3
2 2 3
2 6 4
1 1 3
1 4 2
0 1 walking
0 2 lift
1 2 stairs
2 3 walking
3 4 escalator
5 3 escalator
4 5 walking
5
0 1
1 2
3 5
5 3
5 1

*/
