#include<bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1 | 1)
using namespace std;

const int N = 1429432;

int n, T;

struct Node {
    int l, r, val;
};
struct Tree {
    Node no[4194304 + 4]; // 2^22

    void pushUp(int rt) {
        no[rt].val = no[lson].val + no[rson].val;
    }

    void build(int l, int r, int rt) {
        no[rt].l = l;
        no[rt].r = r;
        if(l == r) {
            no[rt].val = 1;
            return ;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson);
        build(mid + 1, r, rson);

        pushUp(rt);
    }

    void init() {

        build(1, N, 1);

        int k = 0, num, pos;
        while(++k) {
            num = (k > 1 ? find(k, 1) : 2);
            if(num < 0) break;
            for(int i = 1; i * num <= N; i++) {
                pos = i * num;
                erase(pos - i + 1, 1);
            }
        }
    }

    int query(int a, int b, int rt) {
        int l = no[rt].l;
        int r = no[rt].r;
        if(a <= l && b >= r) return no[rt].val;

        int mid = (l + r) >> 1;
        int ans = 0;
        if(a <= mid) ans += query(a, b, lson);
        if(b > mid) ans += query(a, b, rson);
    }

    int erase(int pos, int rt) {
        if(pos > no[rt].val) return -1;//

        int l = no[rt].l;
        int r = no[rt].r;
        if(l == r) {
            no[rt].val = 0;
            return 0;
        }

        int mid = (l + r) >> 1;
        int nums = query(l, mid, lson);

        if(nums >= pos) erase(pos, lson);
        else erase(pos - nums, rson);

        pushUp(rt);
    }

    int find(int pos, int rt) {
        if(pos > no[rt].val) return -1; //

        int l = no[rt].l;
        int r = no[rt].r;
        if(l == r) {
            return l;
        }
        int mid = (l + r) >> 1;
        int nums = query(l, mid, lson);
        if(nums >= pos) return find(pos, lson);
        else return find(pos - nums, rson);
    }
} tree;

int main() {

//    freopen("out.out", "w", stdout);

    tree.init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);
        printf("Case %d: %d\n", ca, tree.find(n, 1));
    }
    return 0;
}
