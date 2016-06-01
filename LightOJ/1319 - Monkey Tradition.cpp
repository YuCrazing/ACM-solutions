#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

void check(ll x) {
    if(x < 0) 1/0;
    return;
}

int p[20], r[20], t[20];
ll M[20];
int main() {
    int T, n;
    ll MM;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        MM = 1;
        for(int i = 0; i < n; i ++) {
            scanf("%d%d", &p[i], &r[i]);
            MM *= p[i];
            check(MM);
        }
        for(int i = 0; i < n; i ++) {
            M[i] = MM / p[i];
            if(M[i] % p[i] == 1) {
                t[i] = 1;
                continue;
            }

            ll tmp = M[i];
            int cnt = 1;
            while(tmp % p[i] != 1) {
                tmp += M[i];
                cnt ++;
                check(tmp);
            }
            t[i] = cnt;
        }
        ll res = 0;
        for(int i = 0; i < n; i ++) res += (ll)r[i] * M[i] * t[i];
        printf("Case %d: %lld\n", cas, res % MM);

    }
    return 0;
}
