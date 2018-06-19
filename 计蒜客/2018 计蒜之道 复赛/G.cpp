#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const ll mod = 1e9+7;
const int N=1e5+5;
char s[N], t[N];
int cs[26], ct[26];
ll f[N], inv[N];

ll qmod(ll a, ll b){
    ll r=1;
    while(b){
        if(b&1) r=r*a%mod;
        a=a*a%mod;
        b >>=1;
    }
    return r;
}
int main(){
    f[0]=inv[0]=1;
    for(int i = 1; i < N; ++i) {
        f[i]=f[i-1]*i%mod;
        inv[i] = qmod(f[i], mod-2);
    }
    int T;
    scanf("%d", &T);
    while(T--){
        memset(cs, 0, sizeof(cs));
        memset(ct, 0, sizeof(ct));
        scanf("%s%s", &s, &t);
        int ls = strlen(s);
        int lt = strlen(t);
        for(int i = 0; i < ls; ++i) cs[s[i]-'a']++;
        for(int i = 0; i < lt; ++i) ct[t[i]-'a']++;
        bool ok=true;
        for(int i = 0; i < 26; ++i) if(ct[i] > cs[i]) {
            ok = false;
            break;
        }
        ll ans=0;
        if(ok){
            ans=1;
            int sum=0;
            for(int i = 0; i < 26; ++i) {
                cs[i] -= ct[i];
                sum+=cs[i];
                ans = ans * inv[cs[i]] % mod;
            }
            ans = ans * f[sum] % mod;
            ans = (ls-lt+1) * ans % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
