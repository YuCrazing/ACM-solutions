#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;

const int N = 202;
const int M = 22;
const int S = 400;
int dp[M][N*40], path[M][N*40], st[N], p[N], d[N], m, n, ca = 0;
int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        if(!m && !n) break;
        for(int i = 0; i < n; i++) scanf("%d%d", &p[i], &d[i]);

        memset(dp,-1, sizeof(dp));
        memset(path,-1, sizeof(path));

        dp[0][S] = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 0; j <= 2*S; j++) {
                for(int k = 0; k < n; k++) {
                    int pre = j - (p[k] - d[k]);
                    if(pre<0 || pre>2*S || dp[i-1][pre]==-1) continue;

                    int t = dp[i-1][pre]+p[k]+d[k];
                    if(t > dp[i][j]) {
                        bool had = false;
                        int las = k, num = i, v = j;
                        while(--num) {
                            v -= p[las]-d[las];
                            las = path[num][v];
                            if(las == k) {
                                had = true;
                                break;
                            }
                        }
                        if(had) continue;

                        dp[i][j] = t;
                        path[i][j] = k;
                    }
                }
            }
        }

        int j, sd, sp;
        for(int i = 0; i <= S; i++) {
            j = S+i;
            if(dp[m][j]!=-1) {
                if(dp[m][S-i]!=-1 && dp[m][S-i]>dp[m][j]) {
                    j = S-i;
                    sp = (-i+dp[m][j])/2;
                    sd = -(-i-dp[m][j])/2;
                } else {
                    sp = (i+dp[m][j])/2;
                    sd = -(i-dp[m][j])/2;
                }

                break;
            }
            j = S-i;
            if(dp[m][j]!=-1) {
                sp = (-i+dp[m][j])/2;
                sd = -(-i-dp[m][j])/2;
                break;
            }
        }

        int las = path[m][j], v = j, num = m;
        while(las!=-1) {
            v -= p[las]-d[las];
            num--;
            st[num] = las;
            las=path[num][v];
        }
        sort(st, st + m);

        printf("Jury #%d\n", ++ca);
        printf("Best jury has value %d for prosecution and value %d for defence:\n", sp, sd);
        for(int i = 0; i < m; i++) printf(" %d", st[i]+1);
        printf("\n\n");
    }
    return 0;
}

/*

3 2
10 1
1 9
1 10

*/
