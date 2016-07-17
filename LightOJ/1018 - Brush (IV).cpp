#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXM = 1 << 16;
const int INF = 0x3f3f3f3f;
struct Point {
    int x,y;
} p[16];
int line[16][16], dp[MAXM], n, T;
vector<int> g[MAXM];

int main() {

    for(int mask = 0; mask < MAXM; mask ++)
        for(int i = 0; i < 16; i ++)
            if(!((1<<i) & mask)) g[mask].push_back(i);

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {

        scanf("%d", &n);

        for(int i = 0; i < n; i ++) scanf("%d%d", &p[i].x, &p[i].y);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++) {
                line[i][j] = 0;
                line[i][j] |= (1<<i);
                line[i][j] |= (1<<j);
                if(i == j) continue;
                for(int k = 0; k < n; k ++)
                        if((p[i].x - p[j].x) * (p[k].y - p[j].y) == (p[k].x - p[j].x) * (p[i].y - p[j].y))
                            line[i][j] |= (1<<k);
            }

        int dst = (1<<n) - 1;
        for(int i = 0; i <= dst; i ++) dp[i] = INF;
        dp[0] = 0;

        for(int mask = 0; mask < dst; mask ++){
            int sz = g[mask].size();
            int u = g[mask][0]; //
            for(int i = 0; i < sz; i ++){
                int v = g[mask][i];
                dp[mask | line[u][v]] = min(dp[mask | line[u][v]], dp[mask] + 1);
            }
        }
        printf("Case %d: %d\n", cas, dp[dst]);
    }
    return 0;
}

