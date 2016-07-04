#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll C(int x) {
    return (ll)(x + 2)*(ll)(x + 1) / 2;
}

ll invalid(int a, int b, int c, int l) {
    int k = (c + l - a - b);
    if(k < 0) return 0; //
    k /= 2; //
    k = min(k, l); //
    return (ll)(k + 1) * (ll)(k + 2) / 2;
}
int main() {
    int a, b, c, l;
    scanf("%d%d%d%d", &a, &b, &c, &l);
    ll res = 0;
    for(int i = 0; i <= l; i++) {
        res += C(i);
        res -= invalid(a, b, c, i);
        res -= invalid(a, c, b, i);
        res -= invalid(c, b, a, i);
    }
    printf("%lld\n",res);
    return 0;
}
