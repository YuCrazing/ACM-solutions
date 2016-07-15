#include <cstdio>
using namespace std;
typedef long long ll;

ll f[33];
ll solve(int x) {
    int t = x;
    int b = 0;
    while(t) {
        b ++;
        t >>= 1;
    }
    t = x;
    ll ans = 0;
    bool one = 0;
    for(int i = b - 1; i >= 0; i --) {
        if(t >= (1<<i)) {
            if(one) ans += t - (1<<i) + 1 + f[i];
            else ans += f[i];
            one = 1;
            t -= (1<<i);
        } else one = 0;
    }
    return ans;
}
int main() {
    f[0] = f[1] = 0;
    for(int i = 2; i < 31; i ++) f[i] = 2 * f[i - 1] + (1 << (i - 2));

    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        printf("Case %d: %lld\n", cas, solve(n));
    }
    return 0;
}
