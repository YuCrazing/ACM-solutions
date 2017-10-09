#include<bits/stdc++.h>
using namespace std;

map<int, int> mp;
int main(){
    int n, x;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        if(mp.find(x)==mp.end()) mp[x]=1;
        else mp[x]++;
    }
    bool ok=false;
    int a,b;
    if(mp.size()==2){
        auto ita=mp.begin();
        auto itb=mp.end();
        itb--;
        if(ita->second==itb->second) ok=true;
        a=ita->first;
        b=itb->first;
    }
    printf(ok?"YES\n":"NO\n");
    if(ok) printf("%d %d\n", a, b);
    return 0;
}
