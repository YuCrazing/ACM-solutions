#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 50010;

int c[MAXN], a[MAXN];

int low(int x) {
    return x&(-x);
}

void add(int a, int x) {
    for(int i = a; i < MAXN; i += low(i)) c[i] += x;
}

int query(int a) {
    int res = 0;
    for(int i = a; i > 0; i -= low(i)) res += c[i];
    return res;
}

int solve(int k, int n) {
    if(query(n) < k) return n + 1;
    int l = 1, r = n;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(query(mid) >= k) r = mid;
        else l = mid + 1;
    }
    return r;
}

int main() {
    //freopen("output.txt", "w", stdout);
    int T, n, q, x;
    char op[5];
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        memset(c, 0, sizeof(c));
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            add(i, 1);
        }
        printf("Case %d:\n", cas);
        for(int i = 0; i < q; i ++) {
            scanf("%s%d", op, &x);
            if(!strcmp(op, "a")) {
                a[++ n] = x;
                add(n, 1);
            } else {
                int k = solve(x, n);
                if(k > n)printf("none\n");
                else {
                    add(k, -1);
                    printf("%d\n", a[k]);
                }
            }
        }
    }
    return 0;
}
