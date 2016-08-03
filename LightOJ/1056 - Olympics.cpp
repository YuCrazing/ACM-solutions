#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int T, l, w;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d : %d", &l, &w);
        double theta = atan(1.0 * w / l);
        double r = sqrt(l * l + w * w) / 2;
        double W = r * 2 * theta;
        double t = l + W;
        printf("Case %d: %.8f %.8f\n", cas, l * 200.0 / t, w * 200.0 / t);
    }
    return 0;
}
