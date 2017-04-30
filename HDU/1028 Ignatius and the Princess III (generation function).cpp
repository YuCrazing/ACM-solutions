#include<bits/stdc++.h>
using namespace std;
/*
    G(x) = 1 * (1 + x + x^2 + x^3 + ... ) * (1 + x^2 + x^4 + x^6 + ...) * (1 + x^3 + x^6 + x^9 + ...) * ...

    (f[i] * x^i) * (1 * x^j) == (f[i] * 1) * x^(i+j)
    f[i + j] * x^(i+j) +=  (f[i] * 1) * x^(i+j)
*/
const int N = 122;
int f[N];
int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for(int num = 1; num <= n; num++) {
            for(int i = n; i >= 0; i--) {
                for(int j = num; j + i <= n; j += num) {
                    f[i + j] += f[i] * 1;
                }
            }
        }
        printf("%d\n", f[n]);
    }
    return 0;
}
