/*
    set is also OK?
    Too slow(842ms)
*/

#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int N=5e4+5;

struct Node {
    int l, r, lb, rb;
};

struct Tree {

    Node no[N<<2];

    void pushDown(int rt) {
        if(no[rt].lb) {
            no[lson].lb=no[rson].lb=no[rt].lb;
            no[rt].lb=0;
        }
        if(no[rt].rb) {
            no[lson].rb=no[rson].rb=no[rt].rb;
            no[rt].rb=0;
        }
    }

    void init(int l, int r, int n, int rt) {
        no[rt].l=l;
        no[rt].r=r;
        no[rt].lb=no[rt].rb=0;
        if(l==r) {
            no[rt].lb=1;
            no[rt].rb=n;
            return;
        }
        int mid=(l+r)>>1;
        init(l, mid, n, lson);
        init(mid+1, r, n, rson);
    }

    void upd(int a, int b, int c, bool ch, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l&&b>=r) {
            if(ch) no[rt].rb=c;
            else no[rt].lb=c;
            return ;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        if(a<=mid) upd(a, b, c, ch, lson);
        if(b>mid) upd(a, b, c, ch, rson);
    }

    int ask(int a, int ch, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(l==r) {
            if(ch==0) return no[rt].lb;
            if(ch==1) return no[rt].rb;
            return (no[rt].lb==-1?0:no[rt].rb-no[rt].lb+1);
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        if(a<=mid) return ask(a, ch, lson);
        else return ask(a, ch, rson);
    }

    void debug(int n) {
        printf("--\n");
        for(int i = 1; i <= n; i++) printf("%d [%d %d]\n", i, ask(i, 0, 1), ask(i, 1, 1));
        printf("--\n");
    }
} tree;

int n, m, x, l, r;
stack<int> pre;
char op[10];
int main() {
    while(scanf("%d%d", &n, &m)!=EOF) {
        tree.init(1, n, n, 1);
        while(!pre.empty()) pre.pop();
        while(m--) {
            scanf("%s", op);
            //tree.debug(n);
            if(op[0]=='D') {
                scanf("%d", &x);
                pre.push(x);
                tree.upd(x, x, -1, 0, 1);
                tree.upd(x, x, -1, 1, 1);
                if(x-1) {
                    l=tree.ask(x-1, 0, 1);
                    if(l!=-1) tree.upd(l, x-1, x-1, 1, 1);
                }
                if(x<n) {
                    r=tree.ask(x+1, 1, 1);
                    if(r!=-1) tree.upd(x+1, r, x+1, 0, 1);
                }
            } else if(op[0]=='Q') {
                scanf("%d", &x);
                printf("%d\n", tree.ask(x, 2, 1));
            } else {
                if(!pre.empty()) {
                    x=pre.top();
                    pre.pop();
                    l=r=-1;
                    if(x-1) l=tree.ask(x-1, 0, 1);
                    if(x<n) r=tree.ask(x+1, 1, 1);
                    if(l==-1) l=x;
                    if(r==-1) r=x;
                    tree.upd(l, r, l, 0, 1);
                    tree.upd(l, r, r, 1, 1);
                }
            }
        }
    }
    return 0;
}
