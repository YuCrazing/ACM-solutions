#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int T;
    ll x1, x2, y1, y2;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);

        ll ans;
        if(x1 == x2 && y1 == y2) ans = 1;
        else ans = __gcd(abs(x1 - x2), abs(y1 - y2)) + 1;

        printf("Case %d: %lld\n", cas, ans);
    }
    return 0;
}
