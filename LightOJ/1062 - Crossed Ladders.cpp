#include<bits/stdc++.h>
using namespace std;
typedef double db;
/*
    ans = c * tan(acos(ans / x)) + c * tan(acos(ans / y))
*/

const db eps = 1e-7;

int T;
db x, y, c;

db f(db a){
    return c * (1.0 / sqrt(x * x - a * a) + 1.0 / sqrt(y * y - a * a)) - 1.0;
}

db search(){
    db l = eps, r = x - eps;
    while(abs(l - r) >= eps){
        db mid = (l + r) / 2;
        if(f(mid) > 0) r = mid;
        else l = mid;
    }
    return l;
}

int main(){
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++){
        scanf("%lf%lf%lf", &x, &y, &c);
        if(x > y) swap(x, y);
        assert(c > 0);
        printf("Case %d: %.6f\n", ca, search());
    }
    return 0;
}
