#include <cstdio>
using namespace std;

int a[111];
double dp[111];
int main() {
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);

        dp[n] = a[n];
        for(int i = n - 1; i > 0; i --) {
            dp[i] = a[i];
            if(i + 6 > n) {
                for(int j = i + 1; j <= n; j ++) dp[i] += dp[j] / (n - i);
            } else {
                for(int j = i + 1;  j <= i + 6; j ++) dp[i] += dp[j] / 6;
            }
        }
        printf("Case %d: %f\n", cas, dp[1]);
    }
    return 0;
}
