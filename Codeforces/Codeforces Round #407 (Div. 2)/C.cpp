#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Segment Tree root is node[1] !!!
    tree.build(1, n, 1) --- YES
    tree.build(1, n, 0) --- NO
*/

const ll INF = 1e19;
const int N = 1e5 + 2;
ll sum[N];

struct Node {
    int l, r;
    ll maxx, minn;
};

struct Tree {
    Node node[N << 2];
    int tol;

    void pushUp(int rt) {
        node[rt].maxx = max(node[rt<<1].maxx, node[rt<<1|1].maxx);
        node[rt].minn = min(node[rt<<1].minn, node[rt<<1|1].minn);
    }

    void build(int l, int r, int rt) {
        node[rt].l = l;
        node[rt].r = r;
        if(l == r) {
            node[rt].maxx = sum[tol + 1];
            node[rt].minn = sum[tol + 1];
            tol ++;
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, rt << 1);
        build(mid + 1, r, rt << 1 | 1);
        pushUp(rt);
    }

    void init(int l, int r, int rt) {
        tol = 0;
        build(l, r, rt);
    }

    ll query(int a, int b, int rt, int ch) {
        int l = node[rt].l;
        int r = node[rt].r;
        int mid = (l + r) >> 1;
        ll ans;

        if(!ch) {
            if(a <= l && b >= r) return node[rt].maxx; // !
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

int a[N], b[N], n;
int main() {

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int sgn = 1;
    sum[0] = 0;
    for(int i = 0; i < n - 1; i++) {
        b[i + 1] = sgn * abs(a[i + 1] - a[i]);
        sgn *= -1;
        sum[i + 1] =  b[i + 1] + sum[i];
    }
    n --;

    tree.init(1, n, 1);

    ll t, ans = -INF;
    for(int i = 1; i <= n; i++) {
        if(i&1) {
            t = tree.query(i, n, 1, 0) - sum[i - 1];
        } else {
            t = -(tree.query(i, n, 1, 1) - sum[i - 1]);
        }
        ans = max(ans, t);
    }
    printf("%I64d\n", ans);
    return 0;
}

