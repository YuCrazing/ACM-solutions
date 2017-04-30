#include<bits/stdc++.h>
using namespace std;

const int N = 101;
const int MAX = N * 101 * 2;

bool f[MAX], t[MAX];
int a[N], n;

void solve() {
    int ans = 0, sum = 0, maxx = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        maxx = max(maxx, a[i]);
    }

    int zero = MAX / 2;

    memset(f, 0, sizeof(f));
    f[zero] = 1;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i + a[k] < MAX; i++) t[i + a[k]] |= f[i];
        for(int i = a[k]; i < MAX; i++) t[i - a[k]] |= f[i]; // range is important.
        for(int i = 0; i < MAX; i++) {
            f[i] |= t[i];
            t[i] = 0;
        }
//        for(int i = 0; i <= sum; i++) printf(i == sum ? "%d\n" : "%d ", f[i]);
    }


    for(int i = zero + 1; i <= zero + sum; i++) if(!f[i]) ans++;
    printf("%d\n", ans);
    for(int i = zero + 1; i <= zero + sum; i++) if(!f[i]) {
            ans --;
            printf(ans ? "%d " : "%d\n", i - zero);
        }

}
int main() {
    while(scanf("%d", &n) != EOF) {
        solve();
    }
    return 0;
}
