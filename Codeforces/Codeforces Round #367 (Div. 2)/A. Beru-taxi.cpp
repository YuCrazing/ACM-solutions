#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
    int a, b, x, y, n, v;
    scanf("%d%d", &a, &b);
    scanf("%d", &n);
    double res = 1e99;
    while(n --) {
        scanf("%d%d%d", &x, &y, &v);
        res = min(res, 1.0*sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v );
    }
    printf("%.10f\n", res);
}
