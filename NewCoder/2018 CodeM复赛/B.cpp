#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int fa[N];
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x, int y){
    int fx=find(x);
    int fy=find(y);
    fa[fx]=fy;
}
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
