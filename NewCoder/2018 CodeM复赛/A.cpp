#include<bits/stdc++.h>
using namespace std;

bool gt(int a, int i, int b, int j){
    if(a==b) return false;
    return log(a)/i > log(b)/j;
}

const int mod=1e9+7;
int a[111], dp[111];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);

    for(int i = 0; i < n; ++i){
        dp[i]=1;
        for(int j = 0; j < i; ++j){
            if(gt(a[i], i+1, a[j], j+1)) dp[i]=(dp[i]+dp[j])%mod;
        }
    }
    int ans=0;
    for(int i = 0; i < n; ++i) ans = (ans + dp[i]) % mod;
    printf("%d\n", ans);
    return 0;
}
