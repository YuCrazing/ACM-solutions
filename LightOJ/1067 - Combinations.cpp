/*
    O(n*log(MOD)) to Preprocess.
    O(1) to query.
*/

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1000003;
ll inv[MOD], fac[MOD];

ll qmod(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}

void init(){
    fac[0] = 1;
    for(ll i = 1; i < MOD; i ++) fac[i] = i * fac[i - 1] % MOD;
    for(ll i = 0; i < MOD; i ++) inv[i] = qmod(fac[i], MOD - 2);
}

int main(){
    init();
    int T, n, k;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &n, &k);
        printf("Case %d: %lld\n", cas, fac[n] * inv[n - k] % MOD * inv[k] % MOD);
    }
    return 0;
}
