#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Point{
    int x, y;
    Point(){}
    Point(int _x, int _y):x(_x),y(_y){}
    Point operator-(const Point b)const{
        return Point(x - b.x, y - b.y);
    }
};
Point p[11111], po;
int main(){
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) scanf("%d%d", &p[i].x, &p[i].y);
        ll sum = 0, b = n;
        for(int i = 0; i < n; i ++){
            sum += (ll)p[i].x * (ll)p[(i+1)%n].y - (ll)p[i].y * (ll)p[(i+1)%n].x;
            po = p[(i+1)%n] - p[i];
            po.x = abs(po.x);
            po.y = abs(po.y);
            if(po.x == 0 || po.y == 0) b += max(po.x, po.y) - 1;
            else{
                int g = __gcd(po.x, po.y);
                int unit = po.x / g;
                if(po.x % unit) b += po.x / unit;
                else b += po.x / unit - 1;
            }

//            if(sum < 0 || b < 0) n /= 0;    // check negative number, n / 0 does't work.
        }
        printf("Case %d: %lld\n", cas, (abs(sum) - b + 2) / 2); // abs(sum) is important.
    }
    return 0;
}
