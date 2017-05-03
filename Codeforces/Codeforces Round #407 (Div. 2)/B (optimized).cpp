#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
unordered_map<int, int> mp;
int main() {
    int b1, q, m, l, x;
    scanf("%d%d%d%d", &b1, &q, &l, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        mp[x] = 1;
    }

    int ans = 0;

    if(q == 0) {
        if(abs(b1) > l) ans = 0;
        else {
            if(mp.find(0) != mp.end()) {
                ans = 1;
                if(mp.find(b1) != mp.end()) ans --;
            } else  ans = 44;
        }
    } else {
        int k = 1, b;
        for(int i = 0; ; i++) {
            if(ans > 40) break;
            if(l / abs(k) < abs(b1)) break;

            b = b1 * k;
            if(mp.find(b) == mp.end()) ans ++;

            if(l / abs(q) < abs(k)) break;
            k *= q;
        }
    }

    if(ans > 40) printf("inf\n");
    else printf("%d\n", ans);
    return 0;
}
