#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;
int a[MAXN];
int main() {
    int T, n, q, op, x, v;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &q);
        long long sum = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
            sum += (long long)a[i] * (long long)(n - (2 * i + 1));
        }
        printf("Case %d:\n", cas);
        while(q --) {
            scanf("%d", &op);
            if(op == 1) printf("%lld\n", sum);
            else {
                scanf("%d%d", &x, &v);
                sum += (long long)(v - a[x]) * (long long)(n - (2 * x + 1));
                a[x] = v;
            }
        }
    }
    return 0;
}
