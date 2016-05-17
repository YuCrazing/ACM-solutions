#include <cstdio>
#include <algorithm>
using namespace std;

int bin[44];

int main() {
    int T, n, x, cnt, ans;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);

        cnt = 0;
        x = n;
        while(x) {
            bin[cnt++] = (x%2 ? 1 : 0);
            x >>= 1;
        }
        bin[cnt++] = 0;

        reverse(bin, bin + cnt);
        next_permutation(bin ,bin + cnt);

        ans = 0;
        for(int i = 0; i < cnt; i++){
            ans <<= 1;
            ans += bin[i];
        }

        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
