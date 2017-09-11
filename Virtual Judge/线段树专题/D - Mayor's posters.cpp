/*
    init()函数中注意要将所有节点的now都置为0
*/

#include<cstdio>
#include<algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int N=1e4+5;

struct Node {
    int l, r, now;
};

struct Tree {

    Node no[N*3*4];

    void pushDown(int rt) {
        if(no[rt].now) {
            no[lson].now=no[rson].now=no[rt].now;
            no[rt].now=0;
        }
    }

    void init(int l, int r, int rt) {
        no[rt].l=l;
        no[rt].r=r;
        no[rt].now=0;//!!
        if(l==r) {
            return;
        }
        int mid=(l+r)>>1;
        init(l, mid, lson);
        init(mid+1, r, rson);
    }

    void update(int a, int b, int c, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l && b>=r) {
            no[rt].now=c;
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
            return no[rt].now;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        if(a<=mid) return ask(a, lson);
        else return ask(a, rson);
    }
} tree;

struct Line {
    int l, r;
} a[N];

int n, m, T, b[N*3];
bool vis[N];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &a[i].l, &a[i].r);
            b[i]=a[i].l;
            b[i+m]=a[i].r;
            b[i+2*m]=a[i].r-1;
            vis[i+1]=0;
        }
        sort(b, b+3*m);
        int k=unique(b, b+3*m)-b;
        tree.init(1, k, 1);
        for(int i = 0; i < m; i++) {
            int l = lower_bound(b, b+k, a[i].l)-b+1;
            int r = lower_bound(b, b+k, a[i].r)-b+1;
            tree.update(l, r, i+1, 1);
        }
        int ans=0;
        for(int i = 1; i <= k; i++) {
            int id=tree.ask(i, 1);
            if(!vis[id]&&id) ans++; //!! id!=0
            vis[id]=true;
        }
        printf("%d\n", ans);
    }
    return 0;
}
