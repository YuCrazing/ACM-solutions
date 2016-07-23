#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
    k = (k - 1 + n) / k;
    double t2 = 1.0 * l / (1.0 * (k - 1) * 2 * v1 * v2 / (v1 + v2) + v2);
    double t1 = (l - v2 * t2) / v1;
    printf("%.10f\n", t1 +  t2);
    return 0;
}
