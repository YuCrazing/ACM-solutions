#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int c[2*N];
ll a[2*N], b[2*N], ans[N];

int main() {
    int n, x;
    ll l, r;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%I64d%I64d", &l, &r);
        a[i] = b[i] = l;
        a[i+n] = b[i+n] = r+1;
    }
    sort(b, b+2*n);
    int m = unique(b, b+2*n) - b;
    for(int i = 0; i < n; ++i) {
        x = lower_bound(b, b+m, a[i]) - b + 1;
        ++c[x];
        x = lower_bound(b, b+m, a[i+n]) - b + 1;
        --c[x];
    }
    for(int i = 1; i < m; ++i) {
        c[i] += c[i-1];
        if(c[i] > 0) ans[c[i]] += b[i] - b[i-1];
    }
    for(int i = 1; i <= n; ++i) printf("%I64d ", ans[i]);
    return 0;
}
