#include<bits/stdc++.h>
using namespace std;

const int N = 502;
int T, n, q, dp[N][N][9];

int max(int& a, int& b, int& c, int& d) {
    int x = a;
    if(b > x) x = b;
    if(c > x) x = c;
    if(d > x) x = d;
    return x;
}

void initRMQ() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            scanf("%d", &dp[i][j][0]);
        }

    for(int j = 1; (1<<j) <= n; j++) {
        for(int x = 0; (x + (1<<j)) - 1 < n; x++) {
            for(int y = 0; (y + (1<<j)) - 1 < n; y++) {
                dp[x][y][j] =
                    max(
                        dp[x][y][j - 1],
                        dp[x + (1<<(j - 1))][y][j - 1],
                        dp[x][y + (1<<(j - 1))][j - 1],
                        dp[x + (1<<(j - 1))][y + (1<<(j - 1))][j - 1]
                    );
            }
        }
    }
}

int RMQ(int x, int y, int s) {
    int x1 = x;
    int y1 = y;
    int x2 = x + s - 1;
    int y2 = y + s - 1;

    int j = 0;
    while((1<<j) <= s) j++;
    j--;

    return
        max(
            dp[x1][y1][j],
            dp[x2 - (1<<j) + 1][y1][j],
            dp[x1][y2 - (1<<j) + 1][j],
            dp[x2 - (1<<j) + 1][y2 - (1<<j) + 1][j]
        );
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &q);
        initRMQ();
        printf("Case %d:\n", ca);
        for(int i = 0; i < q; i++) {
            int x, y, s;
            scanf("%d%d%d", &x, &y, &s);
            printf("%d\n", RMQ(x - 1, y - 1, s));
        }
    }
    return 0;
}
