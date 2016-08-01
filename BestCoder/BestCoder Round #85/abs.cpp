#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = 1LL<<62;
bool ok(ll x) {
    ll sq = sqrt(x);
    for(ll i = 2; i <= sq; i ++) {
        int ct = 0;
        while(x % i == 0) {
            x /= i;
            ct ++;
            if(ct > 1) return false;
        }
    }
    return true;
}

int main() {
    int T;
    ll x;
    scanf("%d", &T);
    while(T --) {
        scanf("%I64d", &x);
        if(x <= 4) printf("%I64d\n", abs(x - 4LL));
        else {
            ll t = sqrt(x);
            ll ans = INF;
            for(ll i = 0; i < 40; i ++) { //
                if(ok(t + i)){
                    ans = min(ans, abs((t + i) * (t + i) - x));
                }
                if(t - i >= 2 && ok(t - i)){
                    ans = min(ans, abs((t - i) * (t - i) - x));
                }
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
