#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2010;
struct Raj{
    int x, y;
    bool operator<(const Raj& b) const{
        if(x < y && b.x < b.y) return x < b.x;
        if(x >= y && b.x >= b.y) return y > b.y;
        return x < y;
    }

}a[MAXN];
ll dp[MAXN][MAXN];
int main(){
    int T, n, k, h;

    scanf("%d", &T);
    while(T --){
        scanf("%d%d%d", &n, &h, &k);
        for(int i = 1; i <= n; i ++) scanf("%d%d", &a[i].x, &a[i].y);

        sort(a + 1, a + n + 1);

        memset(dp, 0 , sizeof(dp));
        for(int i = 0; i <= k; i ++) dp[0][i] = h;
        for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= k; j ++){
            if(dp[i - 1][j] > a[i].x) dp[i][j] = max(dp[i][j], dp[i - 1][j] - a[i].x + a[i].y);
            if(j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        }

        printf((dp[n][k] > 0) ? "Y\n" : "N\n");
    }
    return 0;
}
