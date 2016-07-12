#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 20002;

int pos[MAXN], a[MAXN], dp[MAXN];
int main(){
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
        memset(pos, -1, sizeof(pos));

        int ans = 0;
        for(int i = 0; i < n; i ++){
            int pre = pos[a[i] - 1];
            if(pre != -1) dp[i] = dp[pre] + 1;
            else dp[i] = 1;
            ans = max(ans, dp[i]);

            pos[a[i]] = max(pos[a[i]], i);
        }

        printf("%d\n", ans);
    }
    return 0;
}
