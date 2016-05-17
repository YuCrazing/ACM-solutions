#include <stdio.h>
#include <math.h>

int main() {
    int T;
    long long x, n, y;
    scanf("%d",&T);
    for(int k = 1; k <= T; ++ k) {
        scanf("%lld", &x);
        printf("Case %d: ", k);
        n = (long long)ceil(sqrt(x));

        x -= (n-1) * (n-1);
        y = 2*n - 1 - x;
        if(n%2) {
            if(x == y) printf("%lld %lld\n", n, n);
            else if(x<y) printf("%lld %lld\n", n, x);
            else printf("%lld %lld\n", y + 1, n);
        } else {
            if(x == y) printf("%lld %lld\n", n, n);
            else if(x < y) printf("%lld %lld\n", x, n);
            else printf("%lld %lld\n", n , y + 1);
        }
    }
    return 0;
}
