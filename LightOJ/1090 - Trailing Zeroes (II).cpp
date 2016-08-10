#include <cstdio>
using namespace std;
typedef long long ll;

const int N = 1e6;
int p2[30], p5[30], k2, k5;

void init() {
    p2[0] = p5[0] = 1;
    for(int i = 1; ; i ++) {
        p2[i] = p2[i - 1] * 2;
        if(p2[i] > N) {
            k2 = i;
            break;
        }
    }
    for(int i = 1; ; i ++) {
        p5[i] = p5[i - 1] * 5;
        if(p5[i] > N) {
            k5 = i;
            break;
        }
    }
}

ll calc(int n, int p) {
    ll res = 0;
    if(p == 2) {
        for(int i = 0; i < k2; i ++) {
            if(p2[i] > n) break;
            res += n / p2[i];
        }
    } else {
        for(int i = 0; i < k5; i ++) {
            if(p5[i] > n) break;
            res += n / p5[i];
        }
    }
    return res;
}

int main() {

    init();

    int T, n, r, p, q;
    ll n2, n5;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d%d%d", &n, &r, &p, &q);
        n2 = n5 = 0;

        while(p % 2 == 0) {
            n2 ++;
            p /= 2;
        }
        while(p % 5 == 0) {
            n5 ++;
            p /= 5;
        }

        n2 *= q;
        n5 *= q;

        n2 += calc(n, 2);
        n2 -= calc(n - r, 2);
        n2 -= calc(r, 2);

        n5 += calc(n, 5);
        n5 -= calc(n - r, 5);
        n5 -= calc(r, 5);

        printf("Case %d: %lld\n", cas, (n2 < n5 ? n2 : n5));
    }
    return 0;
}
