#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 30003;
int l[MAXN], r[MAXN], a[MAXN];
int main() {
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i ++) {
            l[i] = i;
            int j = i - 1;
            while(j > 0 && a[j] >= a[i]) j = l[j] - 1;
            l[i] = j + 1;
        }
        for(int i = n; i > 0; i --) {
            r[i] = i;
            int j = i + 1;
            while(j < n + 1 && a[j] >= a[i]) j = r[j] + 1;
            r[i] = j - 1;
        }
        int res = 0;
        for(int i = 1; i <= n; i ++) res = max(res, (r[i] - l[i] + 1) * a[i]);
        printf("Case %d: %d\n", cas, res);
    }
    return 0;
}
