#include<bits/stdc++.h>
using namespace std;

const int N=111;
const int INF=1e9;

struct Edge {
    int u, v, w;
    void read() {
        scanf("%d%d%d", &u, &v, &w);
    }
    bool operator<(const Edge &t)const {
        return w<t.w;
    }
} e[N*N];

int n, m, T, fa[N];
vector<int> edgesOnTree;

void init() {
    for(int i = 1; i <= n; i++) fa[i]=i;
}

int find(int x) {
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}

void merge(int x, int y) {
    int fx=find(x);
    int fy=find(y);
    fa[fy]=fx;
}

int MST(int bad) {
    init();
    int ans=0, cc=n;
    for(int i = 0; i < m; i++) {
        if(i==bad) continue;
        if(find(e[i].u)!=find(e[i].v)) {
            ans+=e[i].w;
            cc--;
            if(bad==-1) edgesOnTree.push_back(i);
            merge(e[i].u, e[i].v);
        }
    }
    if(cc>1) return INF;
    return ans;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        edgesOnTree.clear();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++) e[i].read();
        sort(e, e+m);
        int mi = MST(-1);
        bool ok=true;
        for(int i = 0; i < edgesOnTree.size(); i++) {
            if(MST(edgesOnTree[i])==mi) {
                ok=false;
                break;
            }
        }
        if(ok) printf("%d\n", mi);
        else printf("Not Unique!\n");
    }
    return 0;
}
