/*
    Proof: http://rizoantoufiq.blogspot.com/2015/12/lightoj-1098-new-function.html
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, T;

ll solve() {
    ll ans = 0;
    for(int i = 2; i * i <= n; i++) { // from 2.
        int j = n / i;
        ans += ll(j + i) * ll(j - i + 1) / 2;
        ans += ll(j - i) * ll(i);
    }
    return ans;
}
int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);
        printf("Case %d: %lld\n", ca, solve());
    }
    return 0;
}
