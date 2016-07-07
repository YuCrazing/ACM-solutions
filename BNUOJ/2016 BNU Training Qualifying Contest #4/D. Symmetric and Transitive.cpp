#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 4003;

ll qmod(ll a,ll b) {
    ll res = 1;
    while(b) {
        if(b&1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
ll dp[MAXN][MAXN];
ll bell[MAXN];
int main() {
    for(int i = 0; i < MAXN; i ++) dp[i][0] = dp[0][i] = 0;
    dp[0][0] = 1;
    for(int i = 1; i < MAXN; i ++){
        for(ll j = 1; j <= i; j ++)
            dp[i][j] = (j * dp[i - 1][j] % MOD + dp[i - 1][j - 1]) % MOD;
        bell[i] = 0;
        for(int j = 1; j <= i; j ++) bell[i] = (dp[i][j] + bell[i]) % MOD;
    }
    int n;
    scanf("%d", &n);
    ll sum = 1;
    ll c = 1;
    for(ll i = 1; i < n; i ++) {
        c = ((c * (n - i + 1)) % MOD  * qmod(i, MOD - 2)) % MOD;
        sum  = (sum + bell[i] * c % MOD) % MOD;
    }
    printf("%I64d\n", sum);
    return 0;
}
