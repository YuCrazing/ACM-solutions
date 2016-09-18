#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > g[111];
int main() {
    int T, n, u, v, w;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) g[i]. clear();
        int sum = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back(make_pair(v, 0));
            g[v].push_back(make_pair(u, w));
            sum += w;
        }

        int now = 1, pre = 1, cost = 0;
        do {
            int sz = g[now].size();
            for(int i = 0; i < sz; i ++) {
                v = g[now][i].first;
                w = g[now][i].second;
                if(v == pre) continue;

                cost += w;
                pre = now;
                now = v;
                break;
            }
        } while(now != 1);
        cost = min(sum - cost, cost);
        printf("Case %d: %d\n", cas, cost);
    }
    return 0;
}
