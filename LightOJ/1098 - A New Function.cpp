#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, T;

ll solve() {
    if(n <= 3) return 0;

    ll ans = 0;
    for(int i = 1; ; i++) {
        int l = n / (i + 1) + 1;
        int r = n / i;

//        printf("i == %d [%d %d]\n", i, l, r);

        if(l > r) {
            for(int i = 2; i <= r; i++) ans += (ll)(n/i - 1) * (ll)i;
            break;
        }

        ans += (ll)(i - 1) * (ll)(r - l + 1) *(ll)(r + l) / 2;
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
