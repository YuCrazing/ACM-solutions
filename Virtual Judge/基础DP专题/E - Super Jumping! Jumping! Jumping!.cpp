#include<bits/stdc++.h>
using namespace std;

const int N = 1011;
int n, ans, a[N], dp[N];
int main() {
    while(scanf("%d", &n) != EOF && n) {
        ans = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            int maxx = 0;
            for(int j = 0; j < i; j++) {
                if(a[i] > a[j]) maxx = max(maxx, dp[j]);
            }
            dp[i] = maxx + a[i];
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
