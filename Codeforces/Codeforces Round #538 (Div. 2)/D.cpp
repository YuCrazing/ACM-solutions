#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef double db;

const int INF = 0x3f3f3f3f;
const int N = 5005;
int dp[N][N][2], a[N];

int dfs(int l, int r, int las) {
    int & res = dp[l][r][las];
    if(res != INF) return res;
    if(las == 0) {
        res = min(dfs(l+1, r, 0) + (a[l]!=a[l+1]), dfs(l+1, r, 1) + (a[l]!=a[r]));
    } else {
        res = min(dfs(l, r-1, 0) + (a[r]!=a[l]), dfs(l, r-1, 1) + (a[r]!=a[r-1]));
    }
    return res;
}

int main() {

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];

    memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i < n; ++i) dp[i][i][0] = dp[i][i][1] = 0;

    cout << min(dfs(0, n-1, 0), dfs(0, n-1, 1)) << endl;

    return 0;
}
