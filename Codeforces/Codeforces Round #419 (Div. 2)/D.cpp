#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
//int a[2][N][N];

ll f[N], inv[N], fac[N], a[N];

ll qmod(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b&1) res = res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

void init() {
    f[0] = inv[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = f[i-1]*i%mod;
        inv[i] = qmod(f[i], mod - 2);
    }
}

//void solve(int n) {
//    int pre = 1, cur = 0;
//
//    memset(a[cur], 0, sizeof(a[cur]));
//    for(int i = 1; i <= n; i++) a[cur][i][i] = 1;
//
//    bool add = true;
//    for(int i = n-1; i >= 1; i--) {
//        swap(pre, cur);
//        memset(a[cur], 0, sizeof(a[cur]));
//        for(int j = 1; j <= i; j++) {
//            if(add)for(int k = 1; k <= n; k++) a[cur][j][k] = a[pre][j][k] + a[pre][j+1][k];
//            else for(int k = 1; k <= n; k++) a[cur][j][k] = a[pre][j][k] - a[pre][j+1][k];
//            add = !add;
//        }
//    }
//    printf("%d:  ", n);
//    for(int i = 1; i <= n; i++) printf("%d ", a[cur][1][i]);
//    printf("\n");
//}

ll c(int n, int m) {
    return f[n]*inv[n-m]%mod*inv[m]%mod;
}

void calc(int n) {
    if(n%2==0) {
        int k = n/2-1;
        if(k&1) {
            ll sgn = 1;
            for(int i = 1; i <= n; i++) {
                fac[i] = sgn*c(k, (i-1)/2);
                if(fac[i] < 0) fac[i] += mod;
                sgn *= -1;
            }
        } else {
            for(int i = 1; i <= n; i++) fac[i] = c(k, (i-1)/2);
        }
    } else {
        assert(0);
    }
}

int n;
int main() {
//    for(int n = 1; n < N; n++) {
//        if(n%2 == 0)solve(n);
//    }

    init();

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%I64d", &a[i]);

    ll ans = 0;
    if(n==1) {
        ans = a[1];
    } else {
        if(n%2 == 0) {
            calc(n);
            for(int i = 1; i <= n; i++) a[i] = a[i]*fac[i]%mod;
        } else {
            calc(n-1);
            fac[n] = 0;
//        for(int i = 1; i <= n; i++) printf("%I64d ", fac[i]);
//        printf("\n");
            ll sgn = 1;
            a[1] = fac[1]*a[1]%mod;
            for(int i = 2; i <= n; i++) {
                ll t = sgn*fac[i-1];
                if(t < 0) t += mod;
                a[i] = (fac[i] + t)%mod*a[i]%mod;
                sgn *= -1;
            }
        }
        for(int i = 1; i <= n; i++) ans = (ans + a[i])%mod;
    }

//    for(int i = 1; i <= n; i++) printf("%I64d ", fac[i]);
//    printf("\n");

    printf("%I64d\n", ans);
    return 0;
}
/*

2:  1 1
4:  1 -1 1 -1
6:  1 1 2 2 1 1
8:  1 -1 3 -3 3 -3 1 -1
10:  1 1 4 4 6 6 4 4 1 1
12:  1 -1 5 -5 10 -10 10 -10 5 -5 1 -1
14:  1 1 6 6 15 15 20 20 15 15 6 6 1 1
16:  1 -1 7 -7 21 -21 35 -35 35 -35 21 -21 7 -7 1 -1
18:  1 1 8 8 28 28 56 56 70 70 56 56 28 28 8 8 1 1
20:  1 -1 9 -9 36 -36 84 -84 126 -126 126 -126 84 -84 36 -36 9 -9 1 -1
22:  1 1 10 10 45 45 120 120 210 210 252 252 210 210 120 120 45 45 10 10 1 1
24:  1 -1 11 -11 55 -55 165 -165 330 -330 462 -462 462 -462 330 -330 165 -165 55 -55 11 -11 1 -1
26:  1 1 12 12 66 66 220 220 495 495 792 792 924 924 792 792 495 495 220 220 66 66 12 12 1 1
28:  1 -1 13 -13 78 -78 286 -286 715 -715 1287 -1287 1716 -1716 1716 -1716 1287 -1287 715 -715 286 -286 78 -78 13 -13 1 -1

Process returned 0 (0x0)   execution time : 0.027 s
Press any key to continue.
*/
