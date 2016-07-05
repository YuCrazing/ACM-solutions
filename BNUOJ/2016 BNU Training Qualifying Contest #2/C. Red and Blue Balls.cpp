#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[55];

ll dfs(int x) {
    if(dp[x] != -1) return dp[x];
    ll res = 1;
    for(int i = 1; i < x; i ++) res += dfs(i);
    return dp[x] = res;

}

char s[55];
int main() {
    int n;
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    scanf("%d", &n);
    scanf("%s", s);
    int l = strlen(s);
    ll sum = 0;
    for(int i = 0; i < l; i ++) if(s[i] == 'B') sum += dfs(i + 1);
    printf("%I64d\n", sum);
    return 0;
}
