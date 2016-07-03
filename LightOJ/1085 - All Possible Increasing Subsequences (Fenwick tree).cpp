#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 10;
const int MOD = 1000000007;

int c[MAXN], a[MAXN], b[MAXN];

int low(int x) {
    return x & (-x);
}

void add(int a, int x) {
    for(int i = a; i < MAXN; i += low(i)) c[i] = (c[i] + x) % MOD;
}

int query(int a) {
    int res = 0;
    for(int i = a; i > 0; i -= low(i)) res = (res + c[i]) % MOD;
    return res;
}

int main() {
    int T, n, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        memset(c, 0, sizeof(c));
        for(int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b, b + n);
        int l = unique(b, b + n) - b;
        for(int i = 0; i < n; i ++) a[i] = lower_bound(b, b + l, a[i]) - b + 1;
        for(int i = 0; i < n; i ++) add(a[i], 1 + query(a[i] - 1));
        printf("Case %d: %d\n", cas, query(l));
    }
    return 0;
}
