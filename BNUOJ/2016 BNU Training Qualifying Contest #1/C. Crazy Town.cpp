#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Point {
    int x, y;
};
Point p[2];
int main() {
    int n, sum, a, b, c;
    for(int i = 0; i < 2; i ++ ) scanf("%d%d", &p[i].x, &p[i].y);
    scanf("%d", &n);
    sum = 0;
    for(int i = 0; i < n; i ++) {
        scanf("%d%d%d", &a, &b, &c);
        ll d1 = (ll)a * (ll)p[0].x + (ll)b * (ll)p[0].y + (ll)c;
        ll d2 = (ll)a * (ll)p[1].x + (ll)b * (ll)p[1].y + (ll)c;
        if((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) sum ++;
    }
    printf("%d\n", sum);
    return 0;
}
