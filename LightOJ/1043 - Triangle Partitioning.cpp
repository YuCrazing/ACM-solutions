#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int T;
    double a, b, c, k;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%lf%lf%lf%lf", &a, &b, &c, &k);
        printf("Case %d: %.10f\n", cas, a * sqrt(k/(k + 1)));
    }
    return 0;
}
