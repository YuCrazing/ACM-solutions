/*
    \sum_{i=0}^k {C(k, 2*i)*(q/p)^(2*i)*(1-q/p)^(k-2*i)}
    这是二项式展开的偶数项，设x=1-q/p, y=q/p, 则答案为: [(x+y)^k + (x-y)^k]/2
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll qmod(ll a, ll b) {
    ll r=1;
    while(b) {
        if(b&1) r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}

int T;
ll p, q, k;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%lld%lld%lld", &p, &q, &k);
        ll t1=((p-2*q)%mod+mod)%mod;
        t1=qmod(t1, k);
        ll t2=qmod(p, mod-2);
        t2=qmod(t2, k);
        t1=t1*t2%mod;

        printf("%lld\n", (1+t1)*qmod(2, mod-2)%mod);

    }
    return 0;
}
