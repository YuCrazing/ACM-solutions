#include <cstdio>
#include <cmath>
using namespace std;

const double pi = 2*acos(0.0);
int main(){
    int T;
    double r;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%lf", &r);
        printf("Case %d: %.2f\n", cas, (4.0 - pi) * r *r);
    }
    return 0;
}
