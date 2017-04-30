#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int mod = 1000000007;

int f[N + 2], T, n;

void init() {

    memset(f, 0, sizeof(f));
    f[0] = 1;
    for(int i = 1; i <= N; i++) {
        int sgn = 1, t;
        for(int j = 1; ; j++) {

            t = j * (3 * j - 1) / 2;
            if(t > i) break;
            f[i] += sgn * f[i - t];
            if(f[i] >= mod) f[i] -= mod;
            if(f[i] < 0) f[i] += mod; // !!

            t = j * (3 * j + 1) / 2;
            if(t > i) break;
            f[i] += sgn * f[i - t];
            if(f[i] >= mod) f[i] -= mod;
            if(f[i] < 0) f[i] += mod; // !!

            sgn = -sgn;
        }
    }
}
int main() {

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);
        printf("%d\n", f[n]);
    }
    return 0;
}
