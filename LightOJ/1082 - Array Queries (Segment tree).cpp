#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 2;
const int INF = 0x3f3f3f3f;

struct Node {
    int l, r, val;
};
struct Tree {
    Node node[MAXN<<2];

    void pushUp(int ct) {
        node[ct].val = min(node[ct<<1].val, node[ct<<1|1].val);
    }

    void build(int l, int r, int ct) {
        node[ct].l = l;
        node[ct].r = r;
        node[ct].val = 0;
        if(l == r) {
            scanf("%d", &node[ct].val);
            return ;
        }
        int mid = (l+r)>>1;
        build(l, mid, ct<<1);
        build(mid + 1, r, ct<<1|1);
        pushUp(ct);
    }

    int query(int a, int b, int l, int r, int ct) {
        if(a <= l && b >= r) return node[ct].val;
        int mid = (l+r)>>1;
        int res = INF;
        if(a <= mid) res = min(res, query(a, b, l, mid, ct<<1));
        if(b > mid)  res = min(res, query(a, b, mid + 1, r, ct<<1|1));
        return res;
    }
} tree;

int main() {
    int T, n, q, a, b;
    scanf("%d", &T);

    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &q);
        tree.build(1, n, 1);
        printf("Case %d:\n", cas);
        for(int i = 0; i < q; i ++) {
            scanf("%d%d", &a, &b);
            printf("%d\n", tree.query(a, b, 1, n, 1));
        }
    }
    return 0;
}
