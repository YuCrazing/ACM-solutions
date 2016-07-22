#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int T, n;
    ll A, B, C, x;
    scanf("%d", &T);
    while(T --){
        scanf("%d", &n);
        A = n;
        B = C = 0;
        for(int i = 0; i < n; i ++){
            scanf("%lld", &x);
            if(x < 0) x = -x;
            B += x;
            C += x*x;
        }
        B *= -2;
        ll p = 4 * A * C - B * B;
        ll q = 4 * A;
        ll g = __gcd(p, q);
        printf("%lld/%lld\n", p/g, q/g);
    }
    return 0;
}

/*
    n * alpha^2 - 2*sigma(wi) * alpha + sigma(wi^2)

    when alpha = sigma(wi) / n , get minimum.

    overflow happens if you calculate sigma[(wi - alpha)^2] directly.
*/
