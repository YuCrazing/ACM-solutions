#include <cstdio>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

const int N = 1e5 + 3;
const int inf = 0x3f3f3f3f;
pii dp[N][20];
int mm[N], a[N];
void initRMQ(int n, int b[]) {
    mm[0] = -1;
    for(int i = 1; i <= n; i ++) {
        mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
        dp[i][0] = mp(b[i], b[i]);
        for(int j = 1; j < 20; j ++) {
            dp[i][j].se = inf;
            dp[i][j].fi = 0;
        }
    }
    for(int j = 1; j <= mm[n]; j ++)
        for(int i = 1; i + (1<<j) - 1<= n; i ++) {
            dp[i][j].fi = max(dp[i][j - 1].fi, dp[i + (1<<(j - 1))][j - 1].fi);
            dp[i][j].se = min(dp[i][j - 1].se, dp[i + (1<<(j - 1))][j - 1].se);
        }
}

int rmq(int x, int y) {
    int k = mm[y - x + 1];
    return max(dp[x][k].fi, dp[y - (1<<k) + 1][k].fi) - min(dp[x][k].se, dp[y - (1<<k) + 1][k].se);
}

int main() {
    int T, n, k;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        initRMQ(n, a);
        int res = 0;
        for(int i = 1; i <= n - k + 1; i ++) res = max(res, rmq(i, i + k - 1));
        printf("Case %d: %d\n", cas, res);
    }
    return 0;
}
