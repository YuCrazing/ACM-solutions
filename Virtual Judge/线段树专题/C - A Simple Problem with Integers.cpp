/*
    pushDown()函数中
    no[lson].sum/no[rson].sum/no[lson].add/no[rson].add 都是 += ，不是 =
    init()函数中注意要将所有节点的add都置为0
*/

#include<cstdio>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
typedef long long ll;

const int N=1e5+5;
struct Node {
    int l, r;
    ll add, sum;
};

struct Tree {
    Node no[N<<2];

    void pushUp(int rt) {
        no[rt].sum=no[lson].sum+no[rson].sum;
    }

    void pushDown(int rt) {
        if(no[rt].add) {
            no[lson].sum += no[rt].add*(no[lson].r-no[lson].l+1);
            no[rson].sum += no[rt].add*(no[rson].r-no[rson].l+1);
            no[lson].add += no[rt].add;//!!
            no[rson].add += no[rt].add;//!!
            no[rt].add=0;
        }
    }

    void init(int l, int r, int rt) {
        no[rt].l=l;
        no[rt].r=r;
        no[rt].add=0;//!!
        if(l==r) {
            scanf("%lld", &no[rt].sum);
            return;
        }
        int mid=(l+r)>>1;
        init(l, mid, lson);
        init(mid+1, r, rson);
        pushUp(rt);
    }

    void update(int a, int b, ll c, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l&&b>=r) {
            no[rt].sum+=c*(r-l+1);
            no[rt].add+=c;
            return ;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        if(a<=mid) update(a, b, c, lson);
        if(b>mid) update(a, b, c, rson);
        pushUp(rt);
    }

    ll ask(int a, int b, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l&&b>=r) {
            return no[rt].sum;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        ll ans=0;
        if(a<=mid) ans+=ask(a, b, lson);
        if(b>mid) ans+=ask(a, b, rson);
        return ans;
    }
} tree;
int main() {
    int n, q, x, y, z;
    char op[10];
    while(scanf("%d%d", &n, &q)!=EOF) {
        tree.init(1, n, 1);
        for(int i = 0; i < q; i++) {
            scanf("%s", op);
            if(op[0]=='Q') {
                scanf("%d%d", &x, &y);
                printf("%lld\n", tree.ask(x, y, 1));
            } else {
                scanf("%d%d%d", &x, &y, &z);
                tree.update(x, y, z, 1);
            }
        }
    }
    return 0;
}
