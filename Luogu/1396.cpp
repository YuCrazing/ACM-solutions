#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

struct Edge{
    int u, v, w;
    bool operator<(const Edge& t)const{
        return w < t.w;
    }
}e[N*2];

int n, m, s, t, fa[N];

void init(){
    for(int i = 0; i < n; ++i) fa[i] = i;
}

int find(int x){
    if(x==fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y){
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}

int main(){
    scanf("%d%d%d%d", &n, &m, &s, &t);
    -- s;
    -- t;
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        -- e[i].u;
        -- e[i].v;
    }
    init();
    sort(e, e + m);
    int ans = 0;
    for(int i = 0; i < m; ++i){
        if(find(e[i].u) == find(e[i].v)) continue;
        else merge(e[i].u, e[i].v);

        if(find(s)==find(t)){
            ans = e[i].w;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
