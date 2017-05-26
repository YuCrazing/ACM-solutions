#include<bits/stdc++.h>
using namespace std;

int T;
double a[3];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%lf%lf%lf", &a[0], &a[1], &a[2]);
        sort(a, a + 3);
        printf("%.10f\n", acos(-1.0) * (a[1] * a[1] + (a[2] - a[1]) * (a[2] - a[1])));
    }
    return 0;
}
