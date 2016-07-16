#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXM = 1 << 15;

vector<int> p[MAXM];
int dp[MAXM], h[15];
char a[15][15];

int main() {

    for(int i = 0; i < MAXM; i ++)
        for(int j = 0; j < 15; j ++)
            if((1 << j) & i) p[i].push_back(j);

    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) scanf("%d", &h[i]);
        for(int i = 0; i < n; i ++) scanf("%s", a[i]);

        int dst = (1 << n) - 1;

        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < n; i ++) dp[1<<i] = h[i];

        for(int mask = 1; mask < dst; mask ++)
            for(int i = 0; i < n; i ++)
                if(!((1 << i) & mask)) {
                    int sz = p[mask].size();
                    int maxx = 1;
                    for(int j = 0; j < sz; j ++) maxx = max(maxx, a[p[mask][j]][i] - '0');
                    dp[(1 << i) | mask] = min(dp[(1 << i) | mask], dp[mask] + (h[i] + maxx - 1) / maxx);
                }
        printf("Case %d: %d\n", cas, dp[dst]);
    }
    return 0;
}
