#include <cstdio>
#include <algorithm>
using namespace std;

int T, k, n, a[30], f[30];
int main() {

    f[0] = 1;
    for(int i = 1; i < 6; i ++) f[i] = f[i - 1] * i;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &k);
        for(int i = 0; i < 26; i ++) a[i] = i;

        printf("Case %d:\n", cas);
        for(int i = 0; i < (n < 5 ? min(k, f[n]) : k); i ++) {
            for(int j = 0; j < n; j ++) printf("%c", a[j] + 'A');
            printf("\n");
            next_permutation(a, a +n);
        }
    }
    return 0;
}
