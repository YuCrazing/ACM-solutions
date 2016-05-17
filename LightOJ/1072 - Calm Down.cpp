#include <cstdio>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
int main() {
    int T, n;
    double R;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%lf%d", &R, &n);
        double t = cos((pi - 2*pi/n)/2);
        printf("Case %d: %f\n", cas, t*R / (1+t));
    }
    return 0;
}
