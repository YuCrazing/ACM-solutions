#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,int> exist;
vector<ll> ans;

void add(ll x,int v){
    if(exist.find(x)!=exist.end()) exist[x]=max(exist[x], v);
    else exist[x]=v;
}
void dfs(ll x){
    if(exist.find(x)!=exist.end()){
        if(exist[x]==1){
            dfs(x<<1);
            dfs(x<<1|1);
        }else return;
    } else{
        ans.push_back(x);
        return;
    }
}
int len(ll x) {
    int res=0;
    while(x) {
        x>>=1;
        res++;
    }
    return res;
}
void show(ll x) {
    int l=len(x);
    x<<=(33-l);
    for(int i=24; i>=0; i-=8)printf("%lld%c",((x>>i)&255LL), i?'.':'/');
    printf("%d\n",l-1);
}
int main() {
    int T,n;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++) {
        scanf("%d",&n);
        if(!n) {
            printf("Case #%d:\n1\n0.0.0.0/0\n",cas);
            continue;
        }
        bool ov=false;
        exist.clear();
        for(int i=0; i<n; i++) {
            ll fk=1;
            int bt;
            for(int j=0; j<4; j++) {
                scanf("%d",&bt);
                getchar();
                fk<<=8;
                fk|=bt;
            }
            scanf("%d",&bt);
            if(!bt)ov=true;
            fk>>=(32-bt);
            add(fk, 2);
            while(fk){
                fk>>=1;
                add(fk, 1);
            }
        }
        if(ov) {
            printf("Case #%d:\n0\n",cas);
            continue;
        }

        ans.clear();
        dfs(1);
        printf("Case #%d:\n%d\n",cas,ans.size());
        for(ll as:ans)show(as);
    }
    return 0;
}
