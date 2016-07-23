#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
struct Edge{
    int to, next;
}edge[MAXN << 1];
int head[MAXN], tot, vis[MAXN];

void init(int n){
    for(int i = 1; i <= n; i ++) head[i] = -1;
    tot = 0;
}

void add(int u, int v){
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot ++;

    edge[tot].to = u;
    edge[tot].next = head[v];
    head[v] = tot ++;
}

int n, k;
long long sum = 0; //

int dfs(int u, int fa){
    int sz = vis[u];
    for(int i = head[u]; i != -1; i = edge[i].next){
        int v = edge[i].to;
        if(v == fa) continue;
        sz += dfs(v, u);
    }
    sum += min(k - sz, sz);
    return sz;
}
int main(){
    int  u, v;
    scanf("%d%d", &n, &k);
    init(n);
    k <<= 1;
    for(int i = 0;  i < k; i ++){
        scanf("%d", &u);
        vis[u] = 1;
    }

    for(int i = 0;  i < n - 1; i ++) {
        scanf("%d%d", &u, &v);
        add(u, v);
    }

    dfs(1, 0);

    printf("%I64d\n" ,sum);

    return 0;
}
