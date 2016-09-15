#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

map<ll, ll> mp;
ll p[40];
int ct = 0;
const ll MAX = 1e18;
void init() {
    p[0] = 1;
    for(int i = 1; i < 40; i ++) {
        p[i] = p[i-1] * 5;
        if(p[i] > MAX) {
            ct = i;
            break;
        }
    }
}
ll dfs(ll n) {
    if(n == 0) return 1;
    if(mp.count(n)) return mp[n];
    int x ;
    for(int i = 0; i <= ct; i ++)
        if(p[i] > n) {
            x = i - 1;
            break;
        }

    ll ans = dfs(p[x] - 1);
    if(x & 1) ans += n - p[x] + 1 - dfs(n - p[x]);
    else ans += dfs(n - p[x]);

    return mp[n] = ans;
}
int main() {
    init();
    ll n;
    while(scanf("%lld", &n) != EOF) {
        if(n == -1) break;
        printf("%lld\n", dfs(n));
    }
    return 0;
}
/*
1000000000000000000
2
3
10
100
1000
2000
3000
10000
100000
200000
-1
*/
