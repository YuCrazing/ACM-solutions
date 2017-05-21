/*
    ([n/x] >= y) <==> (n >= x*y)
*/
#include<bits/stdc++.h>
using namespace std;

const int sup = INT_MAX;
const int M = 15;
int ans, sgn, n, m, T, a[M];

int calc(int x) {
    return n / x;
}

void dfs(int val, int start, int num, int tol) {
//    printf("(val:%d cur:%d num:%d tol:%d)\n", val, start, num, tol);
    if(num == tol) {
        ans += sgn * calc(val);
        return ;
    }
    if(start >= m) return ;
    for(int i = start; i <= m - tol + num; i++) {
        int t = a[i] / __gcd(val, a[i]);
        if(n / val >= t) {
            dfs(val * t, i + 1, num + 1, tol);
        }
    }
}

void solve() {
    ans = 0;
    sgn = 1;
    for(int i = 0; i <= m; i++) {
        dfs(1, 0, 0, i);
        sgn *= -1;
    }
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++) scanf("%d", &a[i]);
        sort(a, a + m);
        m = unique(a, a + m) - a;
        solve();
        printf("Case %d: %d\n", ca, ans);
    }
    return 0;
}
