#include <cstdio>
using namespace std;

const int MAXN = 2e5 + 10;
struct Node {
    int nxt, v0, v;
} a[MAXN];

int find(int x) {
    if(a[x].nxt == x) return x;
    return a[x].nxt = find(a[x].nxt);
}

void join(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    a[fx].nxt = a[fy].nxt;
}

int main() {
    int n, m, op, p, x;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i].v0);
        a[i].v = a[i].v0;
        a[i].nxt = i;
    }
    a[n + 1].nxt = n + 1; // important
    scanf("%d", &m);
    for(int q = 0; q < m; q ++) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d", &p, &x);
            int nxt = find(p);
            while(nxt != n + 1) {
                if(x >= a[nxt].v) {
                    x -= a[nxt].v;
                    a[nxt].v = 0;
                    a[nxt].nxt = nxt + 1;
                } else {
                    a[nxt].v -= x;
                    x = 0;
                }
                if(x <= 0) break;
                nxt = a[nxt].nxt;
            }
        } else {
            scanf("%d", &p);
            printf("%d\n", a[p].v0 - a[p].v);
        }
    }
    return 0;
}
