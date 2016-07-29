#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
int a[MAXN], sum[MAXN], T, n, k;
pair<int, int> ans[MAXN];
bool ok(int x) {
    int las = 1;
    int res = 0;
    for(int i = 1; i <= n + 1; i ++) {
        if(sum[i] - sum[las - 1] > x) {
            res ++;
            if(res > k + 1) return false;
            las = i;
        }
    }
    res ++;
    if(res > k + 1) return false;
    return true;
}
int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &k);

        int l = 0, r;
        sum[0] = 0;

        for(int i = 1; i <= n + 1; i ++) {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
            l = max(l, a[i]);
        }

        r = sum[n + 1];
        while(l < r) {
            int mid = (l + r)>>1;
            if(ok(mid)) r = mid;
            else l = mid + 1;
        }
        printf("Case %d: %d\n", cas, l);
        int las = 1;
        int cnt = 1;
        for(int i = 1; i <= n + 1; i ++) {
            if(sum[i] - sum[las - 1] > l) {
                printf("%d\n", sum[i - 1] - sum[las - 1]);
                las = i;
                cnt ++;

            }
            if(n + 1 - i <= k + 1 - cnt) {
                printf("%d\n", sum[i] - sum[las - 1]);
                las = i + 1;
                cnt ++;
            }
        }
    }
    return 0;
}
