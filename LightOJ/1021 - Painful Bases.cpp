#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

int dig[20];
char s[20];
ll dp[1<<16][20];
int main(){
    int T, base, K;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &base, &K);
        scanf("%s", s);
        int l = strlen(s);
        for(int i = 0; i < l; i ++){
            if(s[i] >='A' && s[i] <= 'Z') dig[i] = s[i] - 'A' + 10;
            else dig[i] = s[i] - '0';
        }
        int dst = (1<<l) - 1;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0; i < dst; i ++)
        for(int j = 0; j < l; j ++)
            if(!(i&(1<<j))){
            for(int k = 0; k < K; k ++)
                dp[i | (1<<j)][(k * base + dig[j]) % K] += dp[i][k];
        }
        printf("Case %d: %lld\n", cas, dp[dst][0]);
    }
    return 0;
}
