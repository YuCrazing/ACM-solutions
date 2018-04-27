#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll qpow(ll a, ll b){
    ll r = 1;
    while(b){
        if(b&1) r = r * a;
        a *= a;
        b >>= 1;
    }
    return r;
}

int main() {
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
    int T;
    ll ans;
    char s[30];
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%s", s);
        int l = strlen(s);

        int pos = -1;
        for(int i = 0; s[i]; i++) {
            if((s[i]-'0')%2==1) {
                pos=i;
                break;
            }
        }

        if(pos == -1) ans=0;
        else if(pos == l - 1) {
            ans = 1;
        } else {
            ll d, val;
            d = val = 0;
            for(int i = pos + 1; s[i]; i++) {
                val += s[i]-'0';
                val *= 10;
                d++;
            }
            val /= 10;
            if(s[pos]-'0' == 9) ans = val + 1 + (qpow(10, d) - 1) / 9;
            else ans = min(val + 1 + (qpow(10, d) - 1) / 9, qpow(10, d)-val);
        }

        printf("Case #%d: %lld\n", ca, ans);
    }

    return 0;
}
