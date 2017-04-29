//»ý·Ö
#include <cstdio>
#include <cmath>
#define pi acos(-1.0)
using namespace std;

double F(double x, double k, double b) {
    return x * (k * k / 3 * x * x +  k * b * x + b * b) * pi;
}

int main() {
    int T;
    double r1, r2, h, p;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%lf%lf%lf%lf", &r1, &r2, &h, &p);
        double k = (r2 - r1) / h, b = r1;
        printf("Case %d: %f\n", ca, F(h, k, b) - F(h - p, k, b));
    }
    return 0;
}
