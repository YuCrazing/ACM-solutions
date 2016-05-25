#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int T;
    double L, W;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%lf%lf", &L, &W);
        double x = (L + W - sqrt(W*W + L*L - W*L)) / 6;
        printf("Case %d: %f\n", cas, x * (L - 2*x) * (W - 2*x));

    }
    return 0;
}
