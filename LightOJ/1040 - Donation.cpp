#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 55;
const int MAXM = 55*55;

struct Edge{
    int u, v, w;
    bool operator<(const Edge& b)const{
        return w < b.w;
    }
}edge[MAXM];
int head[MAXN], fa[MAXN], tot;

void init(int n){
    for(int i = 0;i < n; i ++) {
        head[i] = -1;
        fa[i] = i;
    }
    tot = 0;
}

void addedge(int u, int v, int w){
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot ++].w = w;
}

int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y){
    fa[find(x)] = find(y);
}
int main(){
    int T, n, w;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d", &n);
        init(n);
        int sum = 0;
        for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++){
            scanf("%d", &w);
            if(w == 0) continue;
            sum += w;
            addedge(i, j, w);
        }

        int cc = n, cost = 0;
        sort(edge, edge + tot);
        for(int i = 0; i < tot; i ++){
            int u = edge[i].u;
            int v = edge[i].v;
            if(find(u) == find(v)) continue;
            merge(u, v);
            cost += edge[i].w;
            cc --;
        }
        if(cc > 1) sum = -1;
        else sum -= cost;
        printf("Case %d: %d\n", cas, sum);
    }
    return 0;
}
