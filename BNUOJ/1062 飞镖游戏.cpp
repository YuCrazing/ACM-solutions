/*
    Yellow area: (pi/3 + 1 - sqrt(3)) * l^2
    Red area: 4 * (pi/12 - 1 + sqrt(3)/2) * l^2
    Green area: 4 * (1 - pi/6 - sqrt(3)/4) * 1^2
*/

#include<bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;

int main() {

    double p1 = (pi/3 + 1 - sqrt(3));
    double p2 = 4 * (pi/12 - 1 + sqrt(3)/2);
    double p3 = 4 * (1 - pi/6 - sqrt(3)/4);

    int T, a, b, c;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &a, &b, &c);
        printf("%.4f\n", p1*a + p2*b + p3*c);
    }
    return 0;
}
