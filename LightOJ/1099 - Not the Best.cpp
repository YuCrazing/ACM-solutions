#include<bits/stdc++.h>
using namespace std;

const int N = 5003;
const int M = 1e5 + 3;
const int INF = 0x3f3f3f3f;

int n, m, T, dis[N][2], head[N], en;
bool vis[N];

struct Edge {
    int v, w, next;
};

Edge e[M << 1];

void init() {
    en = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v, int w) {
    e[en].v = v;
    e[en].w = w;
    e[en].next = head[u];
    head[u] = en ++;

    e[en].v = u;
    e[en].w = w;
    e[en].next = head[v];
    head[v] = en ++;
}

void spfa(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s][0] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
//        printf("%d: %d %d\n", u, dis[u][0], dis[u][1]);
        assert(dis[u][0] < dis[u][1]);
        vis[u] = 0;
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;
            int len[3];
            len[0] = dis[u][0] + w;
            len[1] = dis[u][1] + w;
            len[2] = dis[u][0] + 3*w;
            bool updated = false;
            if(dis[v][0] > len[0]) {

                int t = min(dis[v][0], len[1]); // Right
                if(dis[v][1] > t) {
                    dis[v][1] = t;
                }

//                if(dis[v][1] > len[1]) { // Why right???
//                    dis[v][1] = len[1];
//                }

                dis[v][0] = len[0];
                updated = true;

            } else if(dis[v][0] == len[0]) {
                if(dis[v][1] > len[1]) {
                    dis[v][1] = len[1];
                    updated = true;
                }
            } else {
                if(dis[v][1] > len[0]) {
                    dis[v][1] = len[0];
                    updated = true;
                }
            }

            if(dis[v][1] > len[2]) {
                dis[v][1] = len[2];
                updated = true;
            }

            if(updated) {
                q.push(v);
                vis[v] = 1;
            }

        }
    }
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        init();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
        }
        spfa(1);
        printf("Case %d: %d\n", ca, dis[n][1]);
    }
    return 0;
}

/*
100
4 4
1 2 5
2 4 10
4 3 7
1 3 7
*/
