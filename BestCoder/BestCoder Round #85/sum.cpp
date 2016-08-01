#include <cstdio>
#include <cstring>
using namespace std;

int dp[5005];
int main(){
    int T, x, m, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n,&m);
        int sum = 0;
        bool ok = 0;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; i ++){
            scanf("%d", &x);
            sum += x;
            sum %= m;

            if(dp[sum] > 0){
                ok = 1;
            }
            dp[sum] ++;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
