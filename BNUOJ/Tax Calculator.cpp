#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int a[5];
int main() {
    int T, x;
    a[1] = 180000;
    a[2] = a[1] + 300000;
    a[3] = a[2] + 400000;
    a[4] = a[3] + 300000;
    double p[5] = {0, 0.1, 0.15, 0.2, 0.25};

    scanf("%d", &T);
    for(int cas = 1;  cas <= T; cas ++) {
        scanf("%d", &x);
        double ans = 0;
        if(x <= a[1]) {
            ans = 0;
        } else {
            for(int i = 1; i < 4; i ++) {
                if(x > a[i]) ans += p[i] * min(x - a[i], a[i + 1] - a[i]);
            }
            if(x > a[4]) ans += p[4] * (x - a[4]);
            ans = max(ceil(ans), (double)2000);
        }
        printf("Case %d: %.0f\n", cas, ans);
    }
    return 0;
