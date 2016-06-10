#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

ll po[50], z[50];
int l = 0;
int zeros(ll n) {
    int pos;
    for(int i = 0; i < n; i ++) {
        if(po[i] > n) {
            pos = i - 1;
            break;
        }
    }
    return pos;
}
map<ll, ll> mp;

ll dfs(ll l, ll r) {
    //printf("%d %d\n", l, r);
    if(r - l < 5) return r - l + 1;
    if(mp.count(r)) return mp[r];
    ll res = 0;
    int pos = zeros(r);
    if(z[pos] & 1) res += r - po[pos] + 1 - dfs(0, r - po[pos]);
    else res += dfs(0, r - po[pos]);

    res += dfs(l, po[pos] - 1);
    mp[r] = res;
    return res;
}
int main() {
    po[0] = 1;
    for(int i = 1; i < 50; i ++) {
        po[i] = 5 * po[i - 1];
        if(po[i] > 1e18) {
            l = i;
            break;
        }
    }

    for(int i = 0; i < l; i ++) {
        z[i] = 0;
        for(int j = 1; j <= i; j ++) z[i] += po[i] / po[j];
    }

    ll n;
    while(scanf("%lld", &n)!=EOF) {
        if(n == -1) break;
        printf("%lld\n", dfs(0, n));
    }
    return 0;
}
