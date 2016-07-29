#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 502;
double dp[N][N];
void init() {

    for(int i = 1; i < N; i ++) {
        dp[0][i] = 1;
        dp[i][0] = 0;
    }

    for(int i = 1; i < N; i ++)
        for(int j = 1; j < N; j ++) {
            dp[i][j] = 0;
            dp[i][j] += 1.0 * i * dp[i - 1][j - 1] / (i + j);
            if(j > 1) dp[i][j] += 1.0 * j * dp[i][j - 2] / (i + j);
            else dp[i][j] = 0;
        }

}
int main() {
    init();
    int T, n, m;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &m);
        printf("Case %d: %f\n", cas, dp[n][m]);
    }
    return 0;
}
