#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int f[N], cost[N];
vector< pair<int,int> > g[N];
int main() {
//    freopen("B-large-practice.in", "r", stdin);
//    freopen("B-large-practice.out", "w", stdout);
    int T, n, m, u, v, w;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) g[i].clear();
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        for(int i = 1; i <= n; ++i) {
            int minCost = 2e5, tar;
            for(int j = 0; j < g[i].size(); ++j) {
                if(g[i][j].second < minCost) {
                    minCost = g[i][j].second;
                    tar = g[i][j].first;
                }
            }
            f[i] = tar;
            cost[i] = minCost;
        }
        long long ans = 1;
        for(int i = 1; i <= n; ++i) {
            if(f[f[i]] == i && i < f[i]) {
                ans *= 2;
            } else if(cost[i] > 0 && cost[f[i]] == 0) {
                ans *= 2;
            }
        }
        printf("Case #%d: %I64d\n", ca, ans);
    }
    return 0;
}
