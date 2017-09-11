/*
    染色是染掉[l, r]之间的实数，不是[l, r]之间的整数
*/

#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int N=8008;

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

    void update(int a, int b, int c, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l&&b>=r) {
            no[rt].col=c;
            return;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        if(a<=mid) update(a, b, c, lson);
        if(b>mid) update(a, b, c, rson);
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

int n, col[N], m, k, a, b, c, pre;

int main() {
    while(scanf("%d", &n)!=EOF) {
        m=k=0;
        tree.init(1, 8000, 1);
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            a++;
            b;
            if(a>b) continue;
            tree.update(a, b, c, 1);
            m=max(m, c);
            k=max(k, b);
        }
        for(int i = 0; i <= m; i++) col[i]=0;
        pre=-1;
        for(int i = 1; i <= k; i++) {
            int cur=tree.ask(i, 1);
            if(cur!=-1) {
                if(cur!=pre) col[cur]++;
            }
            pre=cur;
        }
        for(int i = 0; i <= m; i++) if(col[i]) printf("%d %d\n", i, col[i]);
        printf("\n");
    }
    return 0;
}
