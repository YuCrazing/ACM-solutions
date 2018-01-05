#include<bits/stdc++.h>
using namespace std;

const int N=10010;
int c, y, s, n, mi;
int main() {
    scanf("%d%d", &n, &s);
    mi=1e4;
    long long ans=0;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &c, &y);
        mi+=s;
        if(c<mi) mi=c;
        ans+=1LL*y*mi;
    }
    printf("%lld\n", ans);
    return 0;
}
