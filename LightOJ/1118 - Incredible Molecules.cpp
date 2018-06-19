/*
    分 d*d>=r1*r1-r2*r2 与 d*d<r1*r1-r2*r2 讨论。（r1>r2）
*/

#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1.0)
//const double eps=1e-8;

int x1, y1_, x2, y2, r1, r2;

int main() {
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d%d", &x1, &y1_, &r1);
        scanf("%d%d%d", &x2, &y2, &r2);
        if(r1 <= r2) swap(r1, r2);

        double ans;
        double d = sqrt((x1-x2)*(x1-x2) + (y1_-y2)*(y1_-y2));
        if(d>=r1+r2) ans = 0;
        else if(d<=r1-r2) ans = r2*r2*pi;
        else {
            double a = 2*acos((r1*r1+d*d-r2*r2)/(2*r1*d));
            double b = 2*acos((r2*r2+d*d-r1*r1)/(2*r2*d));
            if(d*d>=r1*r1-r2*r2) ans = r1*r1*a/2-r1*r1*sin(a)/2 + r2*r2*b/2-r2*r2*sin(b)/2;
            else ans = r1*r1*a/2-r1*r1*sin(a)/2 + r2*r2*b/2+r2*r2*sin(2*pi-b)/2;
        }
        printf("Case %d: %f\n", ca, ans);
    }
    return 0;
}
