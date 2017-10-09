#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int N = 200005;

struct Node {
    int val, l, r;
};

struct Tree {

    Node no[N<<2];

    void pushUp(int rt) {
        no[rt].val=max(no[lson].val, no[rson].val);
    }

    void init(int l, int r, int rt) {
        no[rt].l=l;
        no[rt].r=r;
        if(l==r) {
            scanf("%d", &no[rt].val);
            return ;
        }
        int mid=(l+r)>>1;
        init(l, mid, lson);
        init(mid+1, r, rson);
        pushUp(rt);
    }

    void update(int a, int b, int rt) {
        int l = no[rt].l;
        int r = no[rt].r;
        if(l==r) {
            no[rt].val=b;
            return ;
        }
        int mid=(l+r)>>1;
        if(a<=mid) update(a, b, lson);
        else update(a, b, rson);
        pushUp(rt);
    }

    int ask(int a, int b, int rt) {
        int l = no[rt].l;
        int r = no[rt].r;
        if(a<=l&&b>=r) {
            return no[rt].val;
        }
        int mid=(l+r)>>1;
        int ans=0;
        if(a<=mid) ans=max(ans, ask(a, b, lson));
        if(b>mid) ans=max(ans, ask(a, b, rson));
        return ans;
    }

} tree;
int main() {
    int n, m, x, y;
    char op[10];
    while(scanf("%d%d", &n, &m)!=EOF) {
        tree.init(1, n, 1);
        for(int i = 0; i < m; i++) {
            scanf("%s%d%d", op, &x, &y);
            if(op[0]=='Q') printf("%d\n", tree.ask(min(x, y), max(x, y), 1));
            else tree.update(x, y, 1);
        }
    }
    return 0;
}
