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
            } else ans = -1;
        }
    } else if(q == -1) {
        if(l < abs(b1)) ans = 0;
        else {
            if(mp.find(b1) != mp.end() && mp.find(-b1) != mp.end()) ans = 0;
            else ans = -1;
        }
    } else if(q == 1) {
        if(l < abs(b1)) ans = 0;
        else {
            if(mp.find(b1) != mp.end()) ans = 0;
            else ans = -1;
        }
    } else {
        if(b1 == 0) {
            if(mp.find(b1) != mp.end()) ans = 0;
            else ans = -1;
        } else {
            int k = 1, b;
            for(int i = 0; ; i++) {
                if(l / abs(k) < abs(b1)) break;

                b = b1 * k;
                if(mp.find(b) == mp.end()) ans ++;

                if(l / abs(q) < abs(k)) break;
                k *= q;
            }
        }
    }
    assert(ans < 40);
    if(ans == -1) printf("inf\n");
    else printf("%d\n", ans);
    return 0;
}
