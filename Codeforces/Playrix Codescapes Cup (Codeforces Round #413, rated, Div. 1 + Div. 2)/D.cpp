/*
    assume: a < b && h < w:
    it's wrong to use h cover a, use w cover b,
    for example:
        4 6 1 5 2
        2 3
    we should use 1 * 2 * 3 cover 6 and use 5 cover 4.
*/


#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int MAX = 1e5 + 2;
const int N = 55;
int p[MAX];
ll dp[2][MAX], f[N];
int main() {
    int a, b, h, w, n, x;
    scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    sort(p, p + n);

    if(a > b) swap(a, b);
    if(h > w) swap(h, w);
    int ans = -1;
    if(a <= h && b <= w) {
        ans = 0;
    } else {
        int num = 0;
        ll sup = 1e19;
        f[num++] = p[n - 1];
        for(int i = 1; i < N; i++) {
            if(n - 1 - i < 0) break;
            if(sup / f[i - 1] < p[n - 1 - i]) break;
            f[num++] = f[i - 1] * p[n - 1 - i];
        }

        for(int i = 1; i <= w; i++) dp[0][i] = w;
        int pre = 1, now = 0;
        bool ok = false;
        for(int i = 0; i < num; i++) {
            swap(pre, now);
            int k = p[n - 1 - i];
            ll T = f[i];
            for(int j = 1; j <= b; j++) {
                dp[now][j] = dp[pre][j];
                if(dp[now][j] > 0) {
                    ll tt = T / (dp[now][j] / w);
                    if(dp[now][j] >= b && tt >= ((a + h - 1) / h)) {
                        ok = true;
                        ans = i + 1;
                    } else if(dp[now][j] >= a && tt >= ((b + h - 1) / h)) {
                        ok = true;
                        ans = i + 1;
                    }
                    if(ok) break;
                }

                assert(sup / k >= dp[pre][(j + k - 1)/ k]);
                ll t = dp[pre][(j + k - 1)/ k] * k;
                if(t < j) continue;
                if(dp[now][j] < j) dp[now][j] = t;
                else dp[now][j] = min(dp[now][j], t);

                if(dp[now][j] > 0) {
                    ll tt = T / (dp[now][j] / w);
                    if(dp[now][j] >= b && tt >= ((a + h - 1) / h)) {
                        ok = true;
                        ans = i + 1;
                    } else if(dp[now][j] >= a && tt >= ((b + h - 1) / h)) {
                        ok = true;
                        ans = i + 1;
                    }
                    if(ok) break;
                }
            }
            if(ok) break;
        }
        if(!ok) ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}
/*
2 4 1 5 1
2

100000 100000 99999 99999 5
100000 99999 99999 99999 100000

4 6 1 5 2
2 3

*/
