#include<bits/stdc++.h>
using namespace std;
typedef double db;

db A, B, L, R;
int T;

db f(db x) {
    return (B / A) * sqrt(A * A - x * x);
}

db simpson(db a, db b) {
    return ((b - a) / 6) * (f(a) + 4 * f((a + b) / 2) + f(b));
}

db asr(db a, db b, db eps, db val) {
    db c = a + (b - a) / 2;
    db l = simpson(a, c), r = simpson(c, b);
    if(fabs(l + r - val) <= 15 * eps) return l + r + (l + r - val) / 15;
    return asr(a, c, eps / 2, l) + asr(c, b, eps / 2, r);
}

db asr(db a, db b, db eps) {
    return asr(a, b, eps, simpson(a, b));
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%lf%lf%lf%lf", &A, &B, &L, &R);
        printf("%.3f\n", 2 * asr(L, R, 1e-4));
    }
    return 0;
}
