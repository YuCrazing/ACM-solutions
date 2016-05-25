#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int T;
    double a1, a2, v1, v2, v3;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%lf%lf%lf%lf%lf", &v1, &v2, &v3, &a1, &a2);
        printf("Case %d: %f %f\n", cas, v1*v1/(2*a1) + v2*v2/(2*a2), max(v1/a1, v2/a2) * v3);
    }
    return 0;
}
