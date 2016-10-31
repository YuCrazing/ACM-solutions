#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Point {
    ll x, y, z;

    Point(ll _x = 0, ll _y = 0, ll _z = 0) {
        x = _x;
        y = _y;
        z = _z;
    }

//    void read() {
//        scanf("%d%d%d", &x, &y, &z);
//    }
};

ll dis(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}
int main() {
    Point a;
    ll x1, x2, y1, y2, z1, z2;
    while(scanf("%lld%lld%lld", &a.x, &a.y, &a.z) != EOF) {
        scanf("%lld%lld%lld", &x1, &y1, &z1);
        scanf("%lld%lld%lld", &x2, &y2, &z2);
        ll ans = -1;
        if(x1 <= a.x && a.x <= x2 && y1 <= a.y && a.y <= y2 && z1 <= a.z && a.z <= z2) {
            ans = 0;
        } else {
            if(a.z > z2) {
                if(x1 <= a.x && a.x <= x2 && y1 <= a.y && a.y <= y2) ans = (a.z - z2) * (a.z - z2);
                else if(x1 <= a.x && a.x <= x2)
                    ans = min(dis(Point(0, a.y, a.z), Point(0, y1, z2)), dis(Point(0, a.y, a.z), Point(0, y2, z2)));
                else if(y1 <= a.y && a.y <= y2)
                    ans = min(dis(Point(a.x, 0, a.z), Point(x1, 0, z2)), dis(Point(a.x, 0, a.z), Point(x2, 0, z2)));
                else if(a.x >= x2 && a.y <= y1) ans = dis(a, Point(x2, y1, z2));
                else if(a.x >= x2 && a.y >= y2) ans = dis(a, Point(x2, y2, z2));
                else if(a.x <= x1 && a.y >= y2) ans = dis(a, Point(x1, y2, z2));
                else if(a.x <= x1 && a.y <= y1) ans = dis(a, Point(x1, y1, z2));
            } else if(a.z < z1) {
                if(x1 <= a.x && a.x <= x2 && y1 <= a.y && a.y <= y2) ans = (a.z - z1) * (a.z - z1);
                else if(x1 <= a.x && a.x <= x2)
                    ans = min(dis(Point(0, a.y, a.z), Point(0, y1, z1)), dis(Point(0, a.y, a.z), Point(0, y2, z1)));
                else if(y1 <= a.y && a.y <= y2)
                    ans = min(dis(Point(a.x, 0, a.z), Point(x1, 0, z1)), dis(Point(a.x, 0, a.z), Point(x2, 0, z1)));
                else if(a.x >= x2 && a.y <= y1) ans = dis(a, Point(x2, y1, z1));
                else if(a.x >= x2 && a.y >= y2) ans = dis(a, Point(x2, y2, z1));
                else if(a.x <= x1 && a.y >= y2) ans = dis(a, Point(x1, y2, z1));
                else if(a.x <= x1 && a.y <= y1) ans = dis(a, Point(x1, y1, z1));
            } else {
                if(x1 <= a.x && a.x <= x2) ans = min((a.y - y1) * (a.y - y1), (a.y - y2) * (a.y - y2));
                else if(y1 <= a.y && a.y <= y2) ans = min((a.x - x1) * (a.x - x1), (a.x - x2) * (a.x - x2));
                else if(a.x >= x2 && a.y <= y1) ans = dis(Point(a.x, a.y, 0), Point(x2, y1, 0));
                else if(a.x >= x2 && a.y >= y2) ans = dis(Point(a.x, a.y, 0), Point(x2, y2, 0));
                else if(a.x <= x1 && a.y >= y2) ans = dis(Point(a.x, a.y, 0), Point(x1, y2, 0));
                else if(a.x <= x1 && a.y <= y1) ans = dis(Point(a.x, a.y, 0), Point(x1, y1, 0));
            }
            if(ans <= 0) while(1);
        }
        if(ans < 0) while(1);
        printf("%lld\n", ans);
    }

    return 0;
}
/*
0 0 0
1 1 1
2 2 2

1 1 1
0 0 0
2 2 2


1 0 0
1 1 1
2 2 2

1 1 1
1 1 1
2 2 2

-1 -1 -1
1 1 1
2 2 2
*/

