/*
    dfs序
*/

#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int N=5e4+5;

struct Node {
    int l, r, col;
};

struct Tree {

    Node no[N<<2];

    void pushDown(int rt) {
        if(no[rt].col!=-1) {
            no[lson].col=no[rson].col=no[rt].col;
            no[rt].col=-1;
        }
    }

    void init(int l, int r, int rt) {
        no[rt].l=l;
        no[rt].r=r;
        no[rt].col=-1;
        if(l==r) {
            return ;
        }
        int mid=(l+r)>>1;
        init(l, mid, lson);
        init(mid+1, r, rson);
    }

    void upd(int a, int b, int c, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l&&b>=r) {
            no[rt].col=c;
            return;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        if(a<=mid) upd(a, b, c, lson);
        if(b>mid) upd(a, b, c, rson);
    }

    int ask(int a, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(l==r) {
            return no[rt].col;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        if(a<=mid) return ask(a, lson);
        else return ask(a, rson);
    }
} tree;

int tol, h[N], l[N], r[N];
vector<int> g[N];
pair<int, int> dfs(int u) {
    h[u]=++tol;
    pair<int, int> t, res(h[u], h[u]);
    for(int i = 0; i < g[u].size(); i++) {
        int v=g[u][i];
        t=dfs(v);
        res.first=min(res.first, t.first);
        res.second=max(res.second, t.second);
    }
    l[u]=res.first;
    r[u]=res.second;
    return res;
}

int n, m, u, v, x, y, T;
bool in[N];
char op[10];

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);
        tol=0;
        for(int i = 1; i <= n; i++) {
            g[i].clear();
            in[i]=h[i]=0;
        }
        for(int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            g[v].push_back(u);
            in[u]=true;
        }
        for(int i = 1; i <= n; i++) {
            if(!in[i]) {
                dfs(i);
                break;
            }
        }

        tree.init(1, n, 1);
        printf("Case #%d:\n", ca);
        scanf("%d", &m);
        while(m--) {
            scanf("%s%d", op, &x);
            if(op[0]=='T') {
                scanf("%d", &y);
                tree.upd(l[x], r[x], y, 1);
            } else printf("%d\n", tree.ask(h[x], 1));
        }
    }
}
