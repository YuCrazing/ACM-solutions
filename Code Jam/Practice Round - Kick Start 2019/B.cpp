#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sum[5000005];

int main() {

//    ios::sync_with_stdio(false);
//    cin.tie(0);

//    freopen("B-large-practice.in", "r", stdin);
//    freopen("B-large-practice.out", "w", stdout);

    int T, n, ans, x;
    sum[0] = 0;

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        ans = -1;
        for(int i = 1; i <= n; ++i) {
            scanf("%1d", &x);
            sum[i] = sum[i-1] + x;
            if(i >= (n+1)/2) {
                ans = max(ans, sum[i] - sum[i - (n+1)/2]);
            }
        }

        printf("Case #%d: %d\n", ca, ans);

    }
    return 0;
}
