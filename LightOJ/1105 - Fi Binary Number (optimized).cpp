#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 64;
ll f[N];
int T, n, tol;

void init() {
    f[0] = f[1] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = f[i - 1] + f[i - 2];
        if(f[i] > 1e9) {
            tol = i;
            break;
        }
    }
}

int main() {

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);

        int i = tol - 1, l = 0, off = 0;
        char s[66];
        while(i) {
            if(f[i] <= n) {
                n -= f[i];
                s[l++] = '1';
            } else {
                s[l++] = '0';
            }
            i--;
        }
        s[l++] = 0;

        for(; s[off] == '0'; off++); // Remove leading zeros.

        printf("Case %d: %s\n", ca, s + off);
    }

    return 0;
}
