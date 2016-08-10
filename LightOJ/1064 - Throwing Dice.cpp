#include <cstdio>
#include <algorithm>
#define mp make_pair
#define pp first
#define pq second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

pll dp[25][25*6 + 2];

void init() {
    for(int i = 0; i < 25; i ++) {
        dp[i][0] = mp(0, 1);
        for(int j = 1; j < 25*6 + 3; j ++)
            dp[i][j] = mp(1, 1);
    }
    ll p, q, p1, p2, q1, q2, g;
    for(int i = 1; i < 25; i ++) {
        for(int j = 1; j <= 6 * i; j ++) {
            p1 = 0;
            q1 = 1;
            for(int k = 1; k <= 6; k ++) {
                if(j < k) continue;
                p2 = dp[i - 1][j - k].pp;
                q2 = dp[i - 1][j - k].pq;
                g = __gcd(q1, q2);

                q = q1 / g * q2;
                p = q2 / g * p1 + q1 / g * p2;

                g = __gcd(p, q);
                p /= g;
                q /= g;

                p1 = p;
                q1 = q;
            }
            g = __gcd(p1, 6LL);
            p1 /= g;
            q1 *= 6 / g;
            dp[i][j] = mp(p1, q1);
        }
    }
}

int main() {

    init();

    int T, n, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &x);

        ll q = dp[n][x].pq;
        ll p = q - dp[n][x].pp;

        printf("Case %d: ", cas);
        if(q == 1) printf("%lld\n", p);
        else printf("%lld/%lld\n", p, q);
    }
    return 0;
}
