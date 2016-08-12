
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
ll inf  = 1e18;
ll dp[N][2];
int  a[N];
string s[N];
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        cin >> s[i];
        int sz = s[i].size();
    }
    for(int i = 1; i <= n;  i++)
        for(int j = 0; j < 2; j ++)
            dp[i][j] = inf;
    dp[1][0] = 0;
    dp[1][1] = a[1];
    for(int i = 2; i <= n; i ++) {
        if(dp[i - 1][0] != inf) {
            if(s[i] >= s[i - 1]) dp[i][0] = min(dp[i - 1][0], dp[i][0]);
            reverse(s[i].begin(), s[i].end());
            if(s[i] >= s[i - 1]) dp[i][1] = min(dp[i - 1][0] + a[i], dp[i][1]);
            reverse(s[i].begin(), s[i].end());
        }
        if(dp[i - 1][1] != inf) {
            reverse(s[i - 1].begin(), s[i - 1].end());
            if(s[i] >= s[i - 1])  dp[i][0] = min(dp[i - 1][1], dp[i][0]);
            reverse(s[i].begin(), s[i].end());
            if(s[i] >= s[i - 1]) dp[i][1] = min(dp[i - 1][1] + a[i], dp[i][1]);
            reverse(s[i].begin(), s[i].end());
            reverse(s[i - 1].begin(), s[i - 1].end());
        }
    }
    ll ans = inf;
    if(dp[n][0] != inf) ans = min(ans, dp[n][0]);
    if(dp[n][1] != inf) ans = min(ans, dp[n][1]);
    if(ans == inf) cout<< "-1" <<endl;
    else cout << ans << endl;
    return 0;
}
