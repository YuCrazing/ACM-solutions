#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int L=20002;
char s[L];
int suf[L];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    ll ans=0;
    if(n==1 && s[0]=='1')ans=1;
    else {
        ans=(n-1)*n/2;
        suf[n]=0;
        for(int i = n-1; i>=0; --i) suf[i]=(s[i]=='1'?suf[i+1]+1:suf[i+1]);
        for(int i = 1; i < n; ++i) if(s[i]=='1') {
                if(suf[i]==n-i) ans += n-i;
                else ans += n-i-1;
                break;
            }
    }
    printf("%lld\n", ans);
    return 0;
}
