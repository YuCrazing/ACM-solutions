#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
//const int INF = ~0U>>1;
const int MAXN = 111;
const int MAXM = 111 * 111;
struct Edge{
    int next, to, w;
}edge[MAXM];
struct Node{
    int u, min, max, dis;
    Node(int _u = 0, int _max = 0, int _min = 0, int _dis = 0):u(_u),min(_min),max(_max),dis(_dis){}
    bool operator<(const Node& b)const{
        return dis > b.dis;
    }
};
int head[MAXN], tot,dis[MAXN], cost[MAXN], deg[MAXN];
bool vis[MAXN];
void init(){
    tot = 0;
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w){
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dij(int s, int m){
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = cost[s];
    priority_queue<Node> Q;
    Q.push(Node(s, deg[s], deg[s], cost[s]));
    while(!Q.empty()){
        Node t = Q.top();
        Q.pop();

        vis[s] = 1;
        int u = t.u;
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(vis[v]) continue;
            if(max(t.max, deg[v]) - min(t.min, deg[v]) > m) continue;
            if(cost[v] + t.dis + edge[i].w < dis[v]){
                dis[v] = cost[v] + t.dis + edge[i].w;
                Q.push(Node(v, max(t.max, deg[v]), min(t.min, deg[v]), dis[v]));
            }
        }
    }

}

int main(){
    int n, m, p,l,x, v, w;
    scanf("%d%d", &m, &n);
    init();
    for(int i = 1; i <= n; i ++){
        scanf("%d%d%d", &p, &l, &x);
        cost[i] = p;
        deg[i] = l;
        for(int j = 0; j < x; j ++){
            scanf("%d%d", &v, &w);
            addedge(i, v, w - p);
        }
    }
    dij(1, m);
//    for(int i = 1; i <=n; i ++) printf("%d %d\n", i, dis[i]);
    int ans = INF;
    for(int i = 1; i <= n; i ++) ans = min(ans, dis[i]);
    printf("%d\n", ans);
    return 0;
}
