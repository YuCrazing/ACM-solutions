#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 1;
int n, m, T, p[100000], tol, f[N][7];
bool np[N], dif[N];
char fn[N];

void init() {
    tol = 0;
    memset(np, 0, sizeof(np));
    memset(fn, 0, sizeof(fn));
    memset(dif, 0, sizeof(dif));
    dif[1] = 1;

    for(int i = 2; i < N; i++) {
        if(!np[i]) {
            p[tol++] = i;
            f[i][fn[i]++] = i;
            for(int j = i + i; j < N; j += i) {
                np[j] = 1;
                f[j][fn[j]++] = i;
            }
        }

        int t = 1;
        for(int j = 0; j < fn[i]; j++) t *= f[i][j];
        if(t == i) dif[i] = 1;
    }
}

//ll naive(int x) {
//    if(x == 1) return m;
//    ll ans = 0, sgn;
//
//    for(int s = 0; s < (1<<fn[x]); s++) {
//        if(__builtin_popcount(s) & 1) sgn = -1;
//        else sgn = 1;
//
//        ll fac = 1;
//        for(int i = 0; i < fn[x]; i++)
//            if((1<<i) & s) {
//                fac *= f[x][i];
//            }
//
//        ans += sgn * (m / fac);
//    }
//
//    return ans;
//}

ll optimized() {
    ll ans = 2, sgn;

    for(int i = 1; i <= n; i++) {
        if(!dif[i]) continue;
        if(fn[i] & 1) sgn = -1;
        else sgn = 1;
        ans += sgn * ll(n/i) * ll(m/i);
//        printf("%d: ans = %d\n", i, ans);
    }

    return ans;
}

int main() {

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &m);
        if(n > m) swap(n, m);
        ll ans;
        if(!m) {
            ans = 0;
        } else if(n == 0) {
            ans = 1;
        } else {
            ans = optimized();
//            ll t = 2;
//            for(int i = 1; i <= n; i++) {
//                t += naive(i);
//            }
//            assert(t == ans);
        }
        printf("Case %d: %lld\n", ca, ans);
    }
    return 0;
}

/*
100
4 4
10 10
1 1
2 0
0 1000
0 0
2 2
*/
