#include <bits/stdc++.h>
using namespace std;

struct Node {
    int u, w;
    Node(int _u, int _w): u(_u), w(_w) {}
//    bool operator<(const Node & t) const{
//        return w < t.w;
//    }
    bool operator>(const Node & t) const {
        return w > t.w;
    }

};

struct Edge {
    int v, w;
    Edge(int _v, int _w): v(_v), w(_w) {}
};

const int N = 100005;
vector<Edge> g[N];
int dis[N];
bool vis[N];

void Dijkstra(int s) {

    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis)); //!!!!!

    priority_queue< Node, vector<Node>, greater<Node> > Q;

    dis[s] = 0; //!!!!!
    Q.push(Node(s, dis[s]));

    while(!Q.empty()) {
        int u = Q.top().u;
        Q.pop();
        if(vis[u] == true) continue;
        vis[u] = true; //!!!!!
        for(int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].v;
            int w = g[u][i].w;
            if(!vis[v] && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                Q.push(Node(v, dis[v]));
            }
        }
    }
}

int main() {
    int n, m, s, u, v, w;
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(Edge(v, w));
    }
    Dijkstra(s);
    for(int i = 1; i <= n; ++i) printf(i==n?"%d\n":"%d ", dis[i]);
    return 0;
}
