#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N=22;
ll dp[N][N], d[N], len;
void init(ll n){
    len=0;
    while(n){
        d[++len]=n%10;
        n/=10;
    }
    //reverse(d, d+len);
}
ll dfs(int cur, int mod, bool top){
    //printf("%d %d %d\n", cur, mod, top);
    ll &dpp = dp[cur][mod];
    if(dpp!=-1 && top==0) return dpp;
    if(cur==0){
        if(mod==0) return dpp=0;
        else return dpp=1;
    }
    ll ans=0;
    for(int i = 0; i <= (top?d[cur]:9); i++){
        if(i==9) continue;
        if(top && i==d[cur]) ans += dfs(cur-1, (i+mod)%9, 1);
        else ans += dfs(cur-1, (i+mod)%9, 0);
    }
    if(top) return ans;
    else return dpp=ans;
}
int main(){
//    freopen("A-small-attempt0.in", "r", stdin);
//    freopen("A-small-attempt0.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    memset(dp, -1, sizeof(dp));
    int T;
    ll x, y, ax, ay;
//    scanf("%lld",&x);
//    init(x);
//    printf("%lld\n", dfs(len, 0, 1));
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++){
        scanf("%lld%lld", &x, &y);
        init(x-1);
        ax=dfs(len, 0, 1);
        init(y);
        ay=dfs(len, 0, 1);
        //printf("(%lld %lld)\n", ax, ay);
        printf("Case #%d: %lld\n", ca, ay-ax);
    }
    return 0;
}
