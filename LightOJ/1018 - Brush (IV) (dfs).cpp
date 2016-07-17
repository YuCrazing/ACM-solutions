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
vector<int > pivot[MAXM];
int dfs(int mask) {

    if(dp[mask] != INF) return dp[mask];
    if(__builtin_popcount(mask) <= 2) return dp[mask] = 1;

    int res = INF;
    int sz = pivot[mask].size();
    int u, v;
    u = pivot[mask][0];
    for(int j = 1; j < sz; j ++){
        v = pivot[mask][j];
        res = min(1 + dfs(mask & (~line[u][v])), res);
    }
    return dp[mask] = res;
}

int main() {

    for(int mask = 0; mask < MAXM; mask ++)
        for(int i = 0; i < 16; i ++)
                if(((1<<i) & mask)) pivot[mask].push_back(i);


    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {


        scanf("%d", &n);
        for(int i = 0; i < n; i ++) scanf("%d%d", &p[i].x, &p[i].y);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < i; j ++) {
                line[i][j] = line[j][i] = 0;
                line[i][j] |= (1<<i) + (1<<j);
                line[j][i] |= (1<<i) + (1<<j);
                for(int k = 0; k < n; k ++)
                    if(k != i && k != j)
                        if((p[i].x - p[j].x) * (p[k].y - p[j].y) == (p[k].x - p[j].x) * (p[i].y - p[j].y)) {
                            line[i][j] |= (1<<k);
                            line[j][i] |= (1<<k);
                        }
            }

        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;

        printf("Case %d: %d\n", cas, dfs((1<<n) - 1));
    }
    return 0;
}

