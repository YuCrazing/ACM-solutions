#include<bits/stdc++.h>
using namespace std;
const int N = 1503;
int n, q, x, ans, dp[N][N], f[N][26];
string s, ss;

int main() {

    memset(f, -1, sizeof(f));

    scanf("%d", &n);
    cin >> s;

    scanf("%d", &q);
    for(int k = 0; k < q; k++) {
        cin >> x >> ss;
        int id = ss[0] - 'a';
        if(f[x][id] == -1) {
            if(s[0] - 'a' == id) dp[0][0] = 1;
            else dp[0][0] = 0;
            for(int i = 1; i < N; i++) {
                dp[0][i] = 1;
            }
            for(int i = 1; i < n; i++) {
                if(s[i] - 'a' == id) {
                    dp[i][0] = dp[i-1][0] + 1;
                } else {
                    dp[i][0] = 0;
                }

                for(int j = 1; j < N; j++) {
                    if(s[i] -'a' == id) {
                        dp[i][j] = dp[i-1][j] + 1;
                    } else dp[i][j] = dp[i-1][j-1] + 1;
                }
            }
            for(int j = 1; j < N; j++) {
                int maxx = 0;
                for(int i = 0; i < n; i++) {
                    maxx = max(maxx, dp[i][j]);
                }
                f[j][id] = maxx;
            }

        }
        ans = f[x][id];
        printf("%d\n", ans);
    }

    return 0;
}
