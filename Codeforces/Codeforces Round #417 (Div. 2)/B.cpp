#include<bits/stdc++.h>
using namespace std;

int a[20][111], dp[20][2];
char s[111];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    m += 2;
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        for(int j = 0; j < m; j++) {
            a[n - i][j] = s[j] - '0';
        }
    }
    bool ok = 0;
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < m; j++) if(a[i][j]) {
                n = i;
                ok = 1;
                break;
            }
        if(ok) break;
    }

    if(!ok) n = 0;

    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i < n; i++) {
        int right = 0;
        bool has = true;
        for(int j = m - 1; j >= 0; j--)if(a[i][j]) {
                right = j;
                has = 1;
                break;
            }
        int left = m - 1;
        for(int j = 0; j < m; j++)if(a[i][j]) {
                left = j;
                break;
            }

        if(i == 1) {
            dp[i][0] = right*2 + 1;
            dp[i][1] = m;

        } else {
            dp[i][0] = min(dp[i-1][0] + right*2 + 1, dp[i-1][1]+m);
            dp[i][1] = min(dp[i-1][1] + (m - 1 - left)*2 + 1, dp[i-1][0]+m);
        }

//        printf("%d %d\n", dp[i][0], dp[i][1]);

    }
    int ans;
    if(ok) {
        int right = 0;
        for(int i = m - 1; i >= 0; i--)if(a[n][i]) {
                right = i;
                break;
            }
        int left = m - 1;
        for(int i = 0; i < m; i++)if(a[n][i]) {
                left = i;
                break;
            }
        if(n == 1){
            ans = right;
        }else{
            ans = min(dp[n-1][0] + right, dp[n-1][1]+m-1-left);
        }
    } else ans = 0;

    printf("%d\n", ans);

    return 0;
}
