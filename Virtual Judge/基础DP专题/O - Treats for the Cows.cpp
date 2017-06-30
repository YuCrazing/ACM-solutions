#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 2022;
int n, a[N], dp[N][N], sum[N];

int dfs(int l, int r) {
    int &dpp = dp[l][r];
    if(dpp != -1) return dpp;
    if(l == r) return a[l];
    dpp = max(dfs(l, r-1)+sum[r-1]-sum[l-1]+a[r], dfs(l+1, r)+sum[r]-sum[l]+a[l]);
    return dpp;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sum[0] = 0;
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1]+a[i];

    memset(dp, -1, sizeof(dp));
    printf("%d\n", dfs(1, n));
    return 0;
}

/*

4
6
1
10
5

*/
