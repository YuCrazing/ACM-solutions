#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 10002;

ll w[MAXN];
int odd[MAXN];
vector<int> g[MAXN];

ll dfs(int u) {
    int sz = g[u].size();
    if(sz == 0) {
        odd[u] = 1;
        return 1;
    }
    ll res = 0;
    for(int i = 0; i < sz; i ++) {
        int v = g[u][i];
        res = (res + dfs(v) * w[v] % MOD) % MOD;
    }
    int cnt = 0;
    for(int i = 0 ; i < sz; i  ++) {
        int v = g[u][i];
        cnt += (odd[v] & 1) & (w[v] & 1);
    }
    odd[u] = cnt & 1;
    return res;
}
int main() {
    int T, n, fa;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);

        for(int i = 0; i < n; i ++) g[i].clear();
        for(int i = 1; i < n; i ++) {
            scanf("%d", &fa);
            g[fa].push_back(i);
        }

        for(int i = 1; i < n; i ++) scanf("%lld", &w[i]);

        ll ans = dfs(0);
        if(!odd[0]) printf("FREAK OUT\n");
        else printf("%lld\n", ans);
    }
    return 0;
}
