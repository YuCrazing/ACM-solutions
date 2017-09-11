#include<cstdio>
#include<algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int N=5e4+5;

struct Node {
    int l, r, mi, mx;
};

struct Tree {

    Node no[N<<2];

    void pushUp(int rt) {
        no[rt].mx=max(no[lson].mx, no[rson].mx);
        no[rt].mi=min(no[lson].mi, no[rson].mi);
    }

    void init(int l, int r, int rt) {
        no[rt].l=l;
        no[rt].r=r;
        if(l==r) {
            scanf("%d", &no[rt].mi);
            no[rt].mx=no[rt].mi;
            return ;
        }
        int mid=(l+r)>>1;
        init(l, mid, lson);
        init(mid+1, r, rson);
        pushUp(rt);
    }

    int ask(int a, int b, bool ch, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l && b>=r) {
            return (ch?no[rt].mx:no[rt].mi);
        }
        int mid=(l+r)>>1;
        int ans;
        ans=(ch?0:1e9);
        if(a<=mid) ans=(ch? max(ans, ask(a, b, ch, lson)) : min(ans, ask(a, b, ch, lson)));
        if(b>mid) ans=(ch? max(ans, ask(a, b, ch, rson)) : min(ans, ask(a, b, ch, rson)));
        return ans;
    }
} tree;

int n, q, a, b;
int main() {
    scanf("%d%d", &n, &q);
    tree.init(1, n, 1);
    while(q--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", tree.ask(a, b, 1, 1)-tree.ask(a, b, 0, 1));
    }
    return 0;
}
