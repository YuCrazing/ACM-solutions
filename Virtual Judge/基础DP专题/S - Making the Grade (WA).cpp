/*
    (错误的思路)
    op == 0:
    dp[l][r]: 不减，修改最小花费
    x[l][r][0]: 不减，最小花费时的左端点值
    x[l][r][1]: 不减，最小花费时的右端点值

    op == 1:
    dp[l][r]: 不增，修改最小花费
    x[l][r][0]: 不增，最小花费时的左端点值
    x[l][r][1]: 不增，最小花费时的右端点值

    反例：4 2 4 1 3
*/


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 2002;
int a[N], x[N][N][2], n;
ll dp[N][N];

void dfs(int l, int r, int op) {
    if(!op) {
        if(dp[l][r]==-1) {
            if(l==r) {
                dp[l][r] = 0;
                x[l][r][0] = x[l][r][1] = a[l];
            } else {
                //[l, r-1]
                dfs(l, r-1, 0);
                if(a[r]>=x[l][r-1][1]) {
                    x[l][r][0] = x[l][r-1][0];
                    x[l][r][1] = a[r];
                    dp[l][r] = dp[l][r-1];
                } else {
                    x[l][r][0] = x[l][r-1][0];
                    x[l][r][1] = x[l][r-1][1];
                    dp[l][r] = dp[l][r-1]+x[l][r-1][1]-a[r];
                }

                //[l+1, r]
                dfs(l+1, r, 0);
//                if(l == 1 && r == 3) {
//                    printf("%lld %d %d %d\n", dp[l][r], x[l][r][0], x[l][r][1], op);
//                }
                if(a[l]<=x[l+1][r][0]) {
                    if(dp[l+1][r] < dp[l][r]) {

                        x[l][r][0] = a[l];
                        x[l][r][1] = x[l+1][r][1];
                        dp[l][r] = dp[l+1][r];
                    }
                } else {
                    if(dp[l+1][r]+a[l]-x[l+1][r][0] < dp[l][r]) {
                        x[l][r][0] = x[l+1][r][0];
                        x[l][r][1] = x[l+1][r][1];
                        dp[l][r] = dp[l+1][r]+a[l]-x[l+1][r][0];
                    }
                }
            }
//            printf("a[%d] = %d a[%d] = %d ans = %lld\n", l, x[l][r][0], r, x[l][r][1], dp[l][r]);
        }
    } else {
        if(dp[l][r]==-1) {
            if(l==r) {
                dp[l][r] = 0;
                x[l][r][0] = a[l];
                x[l][r][1] = a[l];
            } else {
                //[l, r-1]
                dfs(l, r-1, 1);
                if(a[r]<=x[l][r-1][1]) {
                    x[l][r][0] = x[l][r-1][0];
                    x[l][r][1] = a[r];
                    dp[l][r] = dp[l][r-1];
                } else {
                    x[l][r][0] = x[l][r-1][0];
                    x[l][r][1] = x[l][r-1][1];
                    dp[l][r] = dp[l][r-1]+a[r]-x[l][r-1][1];
                }
//                                if(l == 1 && r == 3) {
////                    printf("%lld %d %d %d\n", dp[l][r], x[l][r][0], x[l][r][1], op);
//                }
                //[l+1, r]
                dfs(l+1, r, 1);
                if(a[l]>=x[l+1][r][0]) {
                    if(dp[l+1][r] < dp[l][r]) {
                        x[l][r][0] = a[l];
                        x[l][r][1] = x[l+1][r][1];
                        dp[l][r] = dp[l+1][r];
                    }
                } else {
                    if(dp[l+1][r]+a[l]-x[l+1][r][0] < dp[l][r]) {
                        x[l][r][0] = x[l+1][r][0];
                        x[l][r][1] = x[l+1][r][1];
                        dp[l][r] = dp[l+1][r]+x[l+1][r][0]-a[l];
                    }
                }
            }
//            printf("a[%d] = %d a[%d] = %d ans = %lld\n", l, x[l][r][0], r, x[l][r][1], dp[l][r]);
        }
    }
}

int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

        memset(dp, -1, sizeof(dp));
        dfs(1, n, 0);
        ll ans = dp[1][n];
        printf("ans = %d\n", ans);
        memset(dp, -1, sizeof(dp));
        dfs(1, n, 1);
        ans = min(ans, dp[1][n]);
        printf("%lld\n", ans);
    }
    return 0;
}

/*

5 1 10 2 2 2

4 2 4 1 3 !!Wrong Answer

4 1 3 5 7
4 1 3 7 5
4 1 5 3 7
4 1 5 7 3
4 1 7 3 5
4 1 7 5 3
4 3 1 5 7
4 3 1 7 5
4 3 5 1 7
4 3 5 7 1
4 3 7 1 5
4 3 7 5 1
4 5 1 3 7
4 5 1 7 3
4 5 3 1 7
4 5 3 7 1
4 5 7 1 3
4 5 7 3 1
4 7 1 3 5
4 7 1 5 3
4 7 3 1 5
4 7 3 5 1
4 7 5 1 3
4 7 5 3 1

*/
