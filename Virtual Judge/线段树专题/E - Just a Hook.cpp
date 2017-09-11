/*
    init()函数中注意要将所有节点的val都置为0!!!
*/


#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int N=1e5+5;

struct Node{
    int l, r, sum, val;
};

struct Tree{

    Node no[N<<2];

    void pushDown(int rt){
        if(no[rt].val){
            no[lson].sum=no[rt].val*(no[lson].r-no[lson].l+1);
            no[rson].sum=no[rt].val*(no[rson].r-no[rson].l+1);
            no[lson].val=no[rson].val=no[rt].val;
            no[rt].val=0;
        }
    }

    void pushUp(int rt){
        no[rt].sum=no[lson].sum+no[rson].sum;
    }

    void init(int l, int r, int rt){
        no[rt].l=l;
        no[rt].r=r;
        no[rt].val=0;//!!
        if(l==r){
            no[rt].sum=1;
            return;
        }
        int mid=(l+r)>>1;
        init(l, mid, lson);
        init(mid+1, r, rson);
        pushUp(rt);
    }

    void update(int a, int b, int c, int rt){
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l&&b>=r){
            no[rt].val=c;
            no[rt].sum=c*(r-l+1);
            return ;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        if(a<=mid) update(a, b, c, lson);
        if(b>mid) update(a, b, c, rson);
        pushUp(rt);
    }

    int ask(int a, int b, int rt){
        int l=no[rt].l;
        int r=no[rt].r;
        if(a<=l&&b>=r){
            return no[rt].sum;
        }
        pushDown(rt);
        int mid=(l+r)>>1;
        int ans=0;
        if(a<=mid) ans+=ask(a, b, lson);
        if(b>mid) ans+=ask(a, b, rson);
        return ans;
    }
}tree;

int n, q, x, y, z, T;
int main(){
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++){
        scanf("%d%d", &n, &q);
        tree.init(1, n, 1);
        for(int i = 0; i < q; i++){
            scanf("%d%d%d", &x, &y, &z);
            tree.update(x, y, z, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", ca, tree.ask(1, n, 1));
    }
    return 0;
}
