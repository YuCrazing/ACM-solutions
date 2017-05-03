//#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;

const ll INF = 1e19;
const int N = 5e4 + 2;
ll sum[N];

struct Node {
    int l, r;
    ll maxx, minn;
};

struct Tree {
    Node node[N << 2];

    void pushUp(int rt) {
        node[rt].maxx = max(node[rt<<1].maxx, node[rt<<1|1].maxx);
        node[rt].minn = min(node[rt<<1].minn, node[rt<<1|1].minn);
    }

    void build(int l, int r, int rt) {
        node[rt].l = l;
        node[rt].r = r;
        if(l == r) {
            scanf("%lld", &node[rt].maxx);
            node[rt].minn = node[rt].maxx;
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, rt << 1);
        build(mid + 1, r, rt << 1 | 1);
        pushUp(rt);
    }


    ll query(int a, int b, int rt, int ch) {

        int l = node[rt].l;
        int r = node[rt].r;
//        printf("[%d %d]\n", l, r);
        int mid = (l + r) >> 1;
        ll ans;

        if(!ch) {
            if(a <= l && b >= r) return node[rt].maxx;
            ans = -INF;
            if(a <= mid) ans = max(ans, query(a, b, rt << 1, 0));
            if(b > mid) ans = max(ans, query(a, b, rt << 1 | 1, 0));
        } else {
            if(a <= l && b >= r) return node[rt].minn;
            ans = INF;
            if(a <= mid) ans = min(ans, query(a, b, rt << 1, 1));
            if(b > mid) ans = min(ans, query(a, b, rt << 1 | 1, 1));
        }
        return ans;
    }

} tree;

int n, q, l, r;
int main() {
    while(scanf("%d%d", &n, &q) != EOF){
        tree.build(1, n, 1);
        for(int i = 0; i < q; i++){
            scanf("%d%d", &l, &r);
            printf("%lld\n", tree.query(l, r, 1, 0) - tree.query(l, r, 1, 1));
        }
    }
    return 0;
}

