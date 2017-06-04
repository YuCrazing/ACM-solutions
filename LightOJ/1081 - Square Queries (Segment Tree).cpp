#include<bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;

const int N = 502;

int T, n, q;

struct NodeY{
    int val, l, r;
};

struct NodeX{
    NodeY no[N << 2];
    int l, r, val;

    pushUp(int rt){
        no[rt].val = max(no[lson].val, no[rson].val);
    }

    void build(int l, int r, int rt){
        no[rt].l = l;
        no[rt].r = r;
        if(l == r){
            scanf("%d", &no[rt].val);
            return ;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson);
        build(mid + 1, r, rson);

        pushUp(rt);
    }

    int query(int l, int r, int rt){
        if(l <= no[rt].l && no[rt].r <= r) return no[rt].val;
        int mid = (l + r) >> 1;
        int ans = 0;
        if(l <= mid) ans = max(ans, query(l, mid, lson));
        if(r > mid) ans = max(ans, query(mid + 1, r, rson));
    }
};

struct Tree{
    NodeX no[N << 2];

    void pushUp(int l, int r, int rt){
        no[rt].val = max(no[lson].val, no[rson].val);
    }
    void build(int l, int r, int rt){
        no[rt].l = l;
        no[rt].r = r;
        if(l == r){
            no[rt].build(1, n, 1);
//            no[rt].val;
            return ;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson);
        build(mid, r, rson);
        pushUp(rt);
    }

    int query(int x1, int y1, int x2, int y2, int rt){
        if()
    }
};

int main(){

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++){

    }
    return 0;
}
