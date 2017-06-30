#include<bits/stdc++.h>
using namespace std;

const int N = 2022;

void getTime(int s) {
    int h = s/3600;
    s -= h*3600;
    h=(h+8)%24;

    int m = s/60;
    s -= m*60;

    if(h < 12) printf("%02d:%02d:%02d am\n", h, m, s);
    else printf("%02d:%02d:%02d pm\n", h, m, s);
}

int n, T, a[N][2], dp[N];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i][0]);
        for(int i = 2; i <= n; i++) scanf("%d", &a[i][1]);
        dp[0] = 0;
        dp[1] = a[1][0];
        for(int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-2]+a[i][1], dp[i-1]+a[i][0]);
        }
        getTime(dp[n]);
    }
    return 0;
}
