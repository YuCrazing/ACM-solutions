/*
    转化为 01 数组中求第 k 个 0 的问题。
*/

#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int N = 50005;

struct Node {
    int sum, l, r;
    bool clear, fill;
};

struct Tree {

    Node no[N<<2];

    void pushUp(int rt) {
        no[rt].sum=no[lson].sum+no[rson].sum;
    }

    void pushDown(int rt) {
        if(no[rt].clear) {
            no[rt].clear=0;
            no[lson].sum=no[rson].sum=0;
            no[lson].clear=no[rson].clear=1;
            no[lson].fill=no[rson].fill=0;
        } else if(no[rt].fill) {
            no[rt].fill=0;
            no[lson].sum=no[lson].r-no[lson].l+1;
            no[rson].sum=no[rson].r-no[rson].l+1;
            no[lson].clear=no[rson].clear=0;
            no[lson].fill=no[rson].fill=1;
        }
    }

    void init(int l, int r, int rt) {
        no[rt].l=l;
        no[rt].r=r;
        no[rt].sum=no[rt].clear=no[rt].fill=0;
        if(l==r) return;
        int mid=(l+r)>>1;
        init(l, mid, lson);
        init(mid+1, r, rson);
        //pushUp();
    }

    void clear(int a, int b, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(l>=a && r<=b) {
            no[rt].sum=0;
            no[rt].clear=1;
            no[rt].fill=0;
            return ;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        if(a<=mid) clear(a, b, lson);
        if(b>mid) clear(a, b, rson);
        pushUp(rt);
    }

    void fill(int a, int b, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(l>=a && r<=b) {
            no[rt].sum=r-l+1;
            no[rt].clear=0;
            no[rt].fill=1;
            return ;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        if(a<=mid) fill(a, b, lson);
        if(b>mid) fill(a, b, rson);
        pushUp(rt);
    }

    int sum(int a, int b, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(l>=a && r<=b) {
            return no[rt].sum;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        int ans=0;
        if(a<=mid) ans += sum(a, b, lson);
        if(b>mid) ans += sum(a, b, rson);
        return ans;
    }

    // k-th empty position
    int kth(int k, int rt) {
        int l=no[rt].l;
        int r=no[rt].r;
        if(l==r) return l;
        pushDown(rt);
        int mid=(l+r)>>1;
        int num=(mid-l+1) - no[lson].sum;
        if(num >= k) return kth(k, lson);
        else return kth(k-num, rson);
    }

    void debug(int n) {
        for(int i = 1; i <= n; ++i) printf("%d ", sum(i, i, 1));
        printf("\n");
    }
} tree;

int main() {
//    freopen("in.in", "r", stdin);
    int T, n, m, op, a, b;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &m);
        tree.init(1, n, 1);
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &op, &a, &b);
            if(op==1) {
                ++a;
                int pre=(a==1?0:a-1-tree.sum(1, a-1, 1));
                int start=(pre+1>n-tree.no[1].sum?-1:tree.kth(pre+1, 1));

                if(start==-1) {
                    printf("Can not put any one.\n");
                } else {
                    int end=tree.kth(min(n-tree.no[1].sum, pre+b), 1);
//                    tree.debug(n);
                    tree.fill(start, end, 1);
//                    tree.debug(n);
                    printf("%d %d\n", --start, --end);
                }

            } else {
                ++a, ++b;
                int sum=tree.sum(a, b, 1);
//                tree.debug(n);
                tree.clear(a, b, 1);
//                tree.debug(n);
                printf("%d\n", sum);
            }
        }
        printf("\n");
    }
    return 0;
}
