#include <stdio.h>
#include <string.h>
const int MOD = 10000007;
int ans[11111];
int f(int n){
    if(ans[n] != -1) return ans[n];
    ans[n] = 0;
    for(int i = 1; i < 7; i++) ans[n] = (ans[n] + f(n - i)) % MOD;
    return ans[n];
}
int main(){
    int T, n, cas = 0;
    scanf("%d", &T);
    while(T--){
        memset(ans, -1, sizeof(ans));
        for(int i = 0; i < 6; i ++){
            scanf("%d", &ans[i]);
            ans[i] %= MOD;
        }
        scanf("%d", &n);
        printf("Case %d: %d\n", ++cas, f(n));
    }
    return 0;
}
