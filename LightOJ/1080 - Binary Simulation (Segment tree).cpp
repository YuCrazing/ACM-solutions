#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1e5+2;
char s[MAXN], op[5];

struct Node {
    int l, r;
    int rev;
};

struct Tree {

    Node node[MAXN<<2];

    void build(int l, int r, int ct) {
        node[ct].l = l;
        node[ct].r = r;
        node[ct].rev = 0;
        if(l == r) {
            node[ct].rev = s[l - 1] - '0';
            return ;
        }
        int mid = (l + r) >> 1;
        build(l, mid, ct<<1);
        build(mid + 1, r, ct<<1|1);
    }

    void pd(int ct) {
        node[ct<<1].rev ^= node[ct].rev;
        node[ct<<1|1].rev ^= node[ct].rev;
        node[ct].rev = 0;
    }

    void update(int a, int b, int l, int r, int ct) {
        if(a <= l && b >= r) {
            node[ct].rev ^= 1;
            return ;
        }
        int mid = (l + r)>>1;
        if(a <= mid) update(a, b, l, mid, ct<<1);
        if(b > mid) update(a, b, mid + 1, r, ct<<1|1);
    }

    int query(int a, int l, int r, int ct) {
        if(l == r) {
            return node[ct].rev;
        }
        pd(ct);
        int mid = (l + r)>>1;
        if(a <= mid) return query(a, l, mid, ct<<1);
        else return query(a, mid + 1, r, ct<<1|1);
    }
} tree;


int main() {
    int T, a, b, q, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%s%d", s, &q);
        n = strlen(s);
        tree.build(1, n, 1);
        printf("Case %d:\n", cas);
        for(int i = 0; i < q; i ++) {
            scanf("%s", op);
            if(!strcmp(op, "I")) {
                scanf("%d%d", &a, &b);
                tree.update(a, b, 1, n, 1);
            } else {
                scanf("%d", &a);
                printf("%d\n", tree.query(a, 1, n, 1));
            }
        }
    }
    return 0;
}
