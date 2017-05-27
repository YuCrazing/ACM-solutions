#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 1;
int n, m, T, f[N], fn[N];
bool np[N];

void init() {
    memset(np, 0, sizeof(np));
    memset(fn, 0, sizeof(fn));

    for(int i = 1; i < N; i++) f[i] = i;

    for(int i = 2; i < N; i++) {
        if(!np[i]) {
            f[i] /= i;
            fn[i]++;
            for(int j = i + i; j < N; j += i) {
                np[j] = 1;
                f[j] /= i;
                fn[j]++;
            }
        }
    }
}

ll optimized() {
    ll ans = 2, sgn;

    for(int i = 1; i <= n; i++) {
        if(f[i] > 1) continue;
        if(fn[i] & 1) sgn = -1;
        else sgn = 1;
        ans += sgn * ll(n/i) * ll(m/i);
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
