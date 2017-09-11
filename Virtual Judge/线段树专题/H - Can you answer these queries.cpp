/*
    暴力更新即可，每个点访问次数最多不超过10次
    坑：输入的查询(x, y)有可能x>y
*/

#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
typedef long long ll;

const int N=1e5+5;

struct Node {
    int l, r;
    ll sum, mx;
};

struct Tree {

    Node no[N<<2];

    void pushUp(int rt) {
        no[rt].mx=max(no[lson].mx, no[rson].mx);
        no[rt].sum=no[lson].sum+no[rson].sum;
    }

    void init(int l, int r, int rt) {
        no[rt].l=l;
        no[rt].r=r;
        if(l==r) {
            scanf("%lld", &no[rt].mx);
            no[rt].sum=no[rt].mx;
            return;
        }
        int mid=(l+r)>>1;
        init(l, mid, lson);
        init(mid+1, r, rson);
        pushUp(rt);
    }

    void sqr(int a, int b, int rt) {
        if(no[rt].mx<=1) return;
        int l=no[rt].l;
        int r=no[rt].r;
        if(l==r) {
            no[rt].mx=(ll)sqrt((double)no[rt].mx+0.5);
            no[rt].sum=no[rt].mx;
            return ;
        }
        int mid=(l+r)>>1;
        if(a<=mid) sqr(a, b, lson);
        if(b>mid) sqr(a, b, rson);
        pushUp(rt);
    }

    ll ask(int a, int b, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l&&b>=r) {
            return no[rt].sum;
        }
        int mid=(l+r)>>1;
        ll ans=0;
        if(a<=mid) ans+=ask(a, b, lson);
        if(b>mid) ans+=ask(a, b, rson);
        return ans;
    }
} tree;

int n, m, x, y, op, ca=0;
int main() {
    while(scanf("%d", &n)!=EOF) {
        tree.init(1, n, 1);
        scanf("%d", &m);
        printf("Case #%d:\n", ++ca);
        while(m--) {
            scanf("%d%d%d", &op, &x, &y);
            if(x>y) swap(x, y);
            if(op) printf("%lld\n", tree.ask(x, y, 1));
            else tree.sqr(x, y, 1);
        }
        printf("\n");
    }
    return 0;
}
