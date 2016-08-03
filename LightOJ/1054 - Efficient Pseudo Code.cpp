#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;

const int N = 47777;
const ll mod = 1000000007;
bool np[N];
ll prime[N];
int cnt;

void init() {
    cnt = 0;
    memset(np, 0, sizeof(np));
    for(ll i = 2; i < N; i ++)
        if(!np[i]) {
            prime[cnt ++] = i;
            for(ll j = i * i; j < N; j += i) np[j] = 1;
        }
}

ll qmod(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll calc(ll x, ll m) {
    if(x == 1) return 1;
    if(m == 0) return 1;
    ll sum = 1;
    for(int i = 0; i < cnt; i ++) {
        if(prime[i] * prime[i] > x) break; //

        ll a = 0;
        while(x % prime[i] == 0) {
            x /= prime[i];
            a ++;
        }

        if(a) {
            ll res = ((qmod(prime[i], a * m + 1) - 1) % mod + mod) % mod;
            res = res * qmod(prime[i] - 1, mod - 2) % mod;
            sum = sum * res % mod;
        }

    }
    if(x > 1) {
        ll res = ((qmod(x, m + 1) - 1) % mod + mod) % mod;
        res = res * qmod(x - 1, mod - 2) % mod;
        sum = sum * res % mod;
    }
    return sum;
}

int main() {
    init();
    int T;
    ll n, m;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%lld%lld", &n, &m);
        printf("Case %d: %lld\n", cas, calc(n, m));
    }
    return 0;
}
