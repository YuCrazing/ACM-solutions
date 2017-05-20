#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1011;
const ll mod = 1000000007;

void add(ll& a, ll b) {
    a += b;
    if(a > mod) a -= mod;
}

void mul(ll& a, ll b) {
    a *= b;
    if(a > mod) a %= mod;
    if(a < 0) a += mod;
}

ll f[N], c[N][N];
int n, m, k, T;

void init() {
    memset(c, 0, sizeof(c));

    f[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = f[i - 1];
        mul(f[i], i);
    }

    for(int i = 0; i < N; i++) c[i][0] = c[i][i] = 1; // c[0][0] should be 1.
    for(int i = 1; i < N; i++)
        for(int j = 1; j < i; j++) {
            add(c[i][j], c[i - 1][j - 1]);
            add(c[i][j], c[i - 1][j]);
        }
}

int main() {
    init();
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d%d", &n, &m, &k);

        ll ans = 0;
        int sgn = 1;
        for(int i = 0; i <= m - k; i++) {
            ll t = c[m - k][i];
            mul(t, f[n - k - i]);
            mul(t, sgn);
            add(ans, t);
            sgn *= -1;
        }
        mul(ans, c[m][k]);

        printf("Case %d: %lld\n", ca, ans);
    }
    return 0;
}
