#include<bits/stdc++.h>
using namespace std;

int main() {
    int p, q, x, y, n;
    scanf("%d", &n);
    while(n --) {
        scanf("%d%d%d%d", &x, &y, &p, &q);
        long long ans;
        if(p == q) {
            if(x == y) ans = 0;
            else ans = -1;
        } else if(p == 0) {
            if(x == 0) ans = 0;
            else ans = -1;
        } else {
            int l = (x + p - 1) / p;
            int r = (y - x + (q - p - 1)) / (q - p);
            l = max(l, r);

//            printf("l == %d, r == %d\n", l, r);
            ans = l * (long long)q - y;
//            printf("%I64d %I64d\n", l*(long long)p - x, ans);

        }
        printf("%I64d\n", ans);
    }

    return 0;
}
