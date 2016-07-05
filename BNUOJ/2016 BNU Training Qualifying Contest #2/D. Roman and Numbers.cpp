#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[1<<18][100];

vector<int> pos[11];
int sz[12];
int main() {
    int m;
    char n[20];
    memset(dp, 0, sizeof(dp));
    memset(sz, 0, sizeof(sz));
    dp[0][0] = 1;
    scanf("%s%d", n, &m);
    int l = strlen(n);
    for(int i = 0; i < l; i ++) pos[n[i] - '0'].push_back(i);
    for(int i = 0; i < 10; i ++) sz[i] = pos[i].size();

    int dst = (1 << l) - 1;

    for(int mask = 0; mask < dst; mask ++) {
        bool ok;
        ok = (mask == 0 ? 1 : 0);
        for(int i = 0; i < l; i ++)
            if((mask & (1<<i)) && n[i] > '0') {
                ok = 1;
                break;
            }
        if(!ok) continue;
        for(int k = 0; k < 10; k ++) {
            int siz = sz[k];
            for(int j = 0; j < siz; j ++) {
                int i = pos[k][j];
                if(!(mask &(1<<i))) {
                    for(int j = 0; j < m; j ++) {
                        dp[mask | (1<<i)][(j * 10 + n[i] - '0') % m]  += dp[mask][j];
                    }
                    break;
                }
            }
        }
//        for(int i = 0; i < m;i ++)
//        printf("dp[%d][%d]=%lld \n", mask, i, dp[mask][i]);
//        printf("\n");
    }
    printf("%I64d\n", dp[dst][0]);
    return 0;
}
