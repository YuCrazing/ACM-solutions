#include <cstdio>
#include <algorithm>
using namespace std;

int cost[22][3],s[22][3], sum[22], ans, n, T;


void init() {
    ans = 0x3f3f3f3f;
}

void dfs(int cur, int last, int res) {
    if(cur == n) {
        ans = min(res, ans);
        return ;
    }
    if(res + sum[cur] >= ans) return ; // pruning
    for(int i = 0; i < 3; i ++) if(i != last) dfs(cur + 1, i, res + cost[cur][i]);
}

int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        init();
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < 3; j ++){
                scanf("%d", &cost[i][j]);
                s[i][j] = cost[i][j];
            }

        for(int i = 0; i < n; i ++) sort(s[i], s[i] + 3);
        sum[n - 1] = s[n - 1][0];
        for(int i = n - 2; i > -1; i --) sum[i] = sum[i + 1] + s[i][0];
        dfs(0, -1, 0);
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
