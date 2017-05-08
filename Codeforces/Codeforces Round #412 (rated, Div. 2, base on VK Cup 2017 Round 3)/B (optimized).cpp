#include<bits/stdc++.h>
using namespace std;
int mod = 475;

bool ok(int s, int p) {
    s /= 50;
    s %= mod;
    for(int i = 0; i <25; i++) {
        s = (s * 96 + 42) % mod;
        if(s + 26 == p) return true;
    }
    return false;
}

int main() {
    int p, x, y;
    scanf("%d%d%d", &p, &x, &y);
    int k = 0, s, ans = -1;
    for(s = x; s >= y; s -= 50) {
        if(ok(s, p)) {
            ans = 0;
            break;
        }
    }
    if(ans < 0) {
        for(s = x + 50; ; s += 50) {
            k ++;
            if(s < y) continue;
            if(ok(s, p)) break;
            if(k > mod) break;
        }
        ans = (k + 1) / 2;
    }
    printf("%d\n", ans);
    return 0;
}
