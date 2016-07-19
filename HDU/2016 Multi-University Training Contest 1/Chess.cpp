#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXM = (1<<20) + 3;
int dp[MAXM];
int dfs(int x) {

    if(dp[x] != -1) return dp[x];

    int t = x;
    bool ok = 1;
    while(t) {
        if(!(t & 1)) ok = 0;
        t >>= 1;
    }

    if(ok) return dp[x] = 0;
    int vis[20];
    memset(vis, 0, sizeof(vis));
    for(int i = 0;  i < 20; i ++) if((1 << i) & x) {
            for(int j = i; j > - 1; j --) {
                if(!((1<<j) & x)) {
                    vis[dfs((x ^ (1 << i) )| (1<<j))] = 1;
                    break;
                }
            }
        }
    int i = 0;
    while(vis[i]) i++;
    return dp[x] = i;
}
int main() {
    memset(dp, -1, sizeof(dp));
    int n, T, pos, k;
    scanf("%d", &T);
    while(T --) {
        scanf("%d", &n);
        int ans = 0;
        for(int i = 0; i < n;  i++) {
            int x = 0;
            scanf("%d", &k);
            while(k--) {
                scanf("%d", &pos);
                x |= 1<<(20-pos);
            }
            ans ^= dfs(x);
        }
        if(ans)printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
