#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5e4 + 2;
int l[N], r[N];

int main() {
    int T, n, q, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {

        scanf("%d%d", &n, &q);
        for(int i = 0; i < n; i ++) scanf("%d%d", &l[i], &r[i]);

        sort(l, l + n);
        sort(r, r + n);

        printf("Case %d:\n", cas);
        for(int i = 0; i < q; i ++) {
            scanf("%d", &x);
            printf("%d\n", (upper_bound(l, l + n, x) - l) - (lower_bound(r, r + n, x) - r));
        }
    }
    return 0;
}
