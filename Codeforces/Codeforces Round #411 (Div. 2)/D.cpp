#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

ll qmod(ll a, int b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

char s[1000010];
int main(){
    scanf("%s", s);
    int l = strlen(s);
    ll ans = 0;
    ll b = 0, sum = 0;
    for(int i = l - 1; i >= 0; i--){
        if(s[i] == 'b') b++;
        else if(s[i] == 'a'){
            sum = 2 * sum % mod;
            sum = (sum + b) % mod;
            b = 0;
            ans = (ans + sum) % mod;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
